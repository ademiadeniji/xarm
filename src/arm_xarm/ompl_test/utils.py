import os
import subprocess

import message_filters
import numpy as np
import open3d
import openvr
import trimesh
from rlbench.backend.observation import Observation
from scipy.spatial.transform import Rotation as R

from ompl_test import geometry
import tf.transformations as ttf


def tsdf_from_depth(depth, camera_to_base, K):
    depth = np.copy(depth)
    depth[:, -40:] = np.nan
    T_camera_to_base = geometry.transformation_matrix(*camera_to_base)
    volume = open3d.integration.ScalableTSDFVolume(
        voxel_length=0.005,
        sdf_trunc=0.04,
        color_type=open3d.integration.TSDFVolumeColorType.Gray32,
    )
    rgbd = open3d.geometry.RGBDImage.create_from_color_and_depth(
        open3d.geometry.Image(depth),
        open3d.geometry.Image((depth * 1000).astype(np.uint16)),
        #depth_trunc=2.0,
        depth_trunc=1.4,
    )
    volume.integrate(
        rgbd,
        open3d.camera.PinholeCameraIntrinsic(
            width=depth.shape[1],
            height=depth.shape[0],
            fx=K[0, 0],
            fy=K[1, 1],
            cx=K[0, 2],
            cy=K[1, 2],
        ),
        np.linalg.inv(T_camera_to_base),
    )
    mesh = volume.extract_triangle_mesh()
    mesh = mesh.simplify_vertex_clustering(voxel_size=0.02)
    vertices = np.asarray(mesh.vertices)
    faces = np.asarray(mesh.triangles)
    mesh = trimesh.Trimesh(
        vertices=vertices,
        faces=np.r_[faces, faces[:, ::-1]],
    )
    return mesh


def matrix_from_openvr_pose(pose):
    if not isinstance(pose, openvr.HmdMatrix34_t):
        raise TypeError(f"Type of pose must be {openvr.HmdMatrix34_t}")

    matrix = np.array(
        [
            [pose[0][0], pose[0][1], pose[0][2], pose[0][3]],
            [pose[1][0], pose[1][1], pose[1][2], pose[1][3]],
            [pose[2][0], pose[2][1], pose[2][2], pose[2][3]],
            [0, 0, 0, 1],
        ],
        dtype=np.float64,
    )
    # # Map x->-x, y->z, z->y
    matrix = (
            ttf.rotation_matrix(np.deg2rad(180), [0, 1, 0])
            @ ttf.rotation_matrix(np.deg2rad(-90), [1, 0, 0])
            @ matrix
    )

    return matrix


def scale_transformation(transformation_matrix, scale):
    translation = ttf.translation_from_matrix(transformation_matrix)
    ai, aj, ak = ttf.euler_from_matrix(transformation_matrix)
    transformation_matrix = ttf.euler_matrix(
        ai * scale, aj * scale, ak * scale
    )
    transformation_matrix[:3, 3] = translation * scale
    return transformation_matrix


def dict_from_controller_state(pControllerState):
    # https://github.com/ValveSoftware/openvr/wiki/IVRSystem::GetControllerState
    d = {}
    d["unPacketNum"] = pControllerState.unPacketNum
    # on trigger .y is always 0.0 says the docs
    d["trigger"] = pControllerState.rAxis[1].x
    # 0.0 on trigger is fully released
    # -1.0 to 1.0 on joystick and trackpads
    d["trackpad_x"] = pControllerState.rAxis[0].x
    d["trackpad_y"] = pControllerState.rAxis[0].y
    # These are published and always 0.0
    # for i in range(2, 5):
    #     d['unknowns_' + str(i) + '_x'] = pControllerState.rAxis[i].x
    #     d['unknowns_' + str(i) + '_y'] = pControllerState.rAxis[i].y
    d["ulButtonPressed"] = pControllerState.ulButtonPressed
    d["ulButtonTouched"] = pControllerState.ulButtonTouched
    # To make easier to understand what is going on
    # Second bit marks menu button
    d["menu_button"] = bool(pControllerState.ulButtonPressed >> 1 & 1)
    # 32 bit marks trackpad
    d["trackpad_pressed"] = bool(pControllerState.ulButtonPressed >> 32 & 1)
    d["trackpad_touched"] = bool(pControllerState.ulButtonTouched >> 32 & 1)
    # third bit marks grip button
    d["grip_button"] = bool(pControllerState.ulButtonPressed >> 2 & 1)
    # System button can't be read, if you press it
    # the controllers stop reporting

    trackpad_pressed_button = "none"
    if d["trackpad_pressed"]:
        x = d["trackpad_x"]
        y = d["trackpad_y"]
        assert -1 <= x <= 1
        assert -1 <= y <= 1
        if -0.5 <= x <= 0.5 and -1 <= y <= -0.5:
            trackpad_pressed_button = "bottom"
        elif -0.5 <= x <= 0.5 and 0.5 <= y <= 1:
            trackpad_pressed_button = "top"
        elif -1 <= x <= -0.5 and -0.5 <= y <= 0.5:
            trackpad_pressed_button = "left"
        elif 0.5 <= x <= 1 and -0.5 <= y <= 0.5:
            trackpad_pressed_button = "right"
        elif -0.5 <= x <= 0.5 and -0.5 <= y <= 0.5:
            trackpad_pressed_button = "center"
    d["trackpad_pressed_button"] = trackpad_pressed_button

    return d


def pointcloud_from_depth(
    depth: np.ndarray,
    fx: float,
    fy: float,
    cx: float,
    cy: float,
) -> np.ndarray:
    assert depth.dtype.kind == "f", "depth must be float and have meter values"

    rows, cols = depth.shape
    c, r = np.meshgrid(np.arange(cols), np.arange(rows), sparse=True)
    valid = ~np.isnan(depth)
    z = np.where(valid, depth, np.nan)
    x = np.where(valid, z * (c - cx) / fx, np.nan)
    y = np.where(valid, z * (r - cy) / fy, np.nan)
    pc = np.dstack((x, y, z))

    return pc


def recover_xarm_from_error():
    # subprocess.call(["rosservice", "call", "/xarm/clear_err"],
    #                 stdout=open(os.devnull, "w"), stderr=subprocess.STDOUT)
    subprocess.call(["rosservice", "call", "/xarm/moveit_clear_err"],
                    stdout=open(os.devnull, "w"), stderr=subprocess.STDOUT)


def real_obs_to_rlbench_obs(obs: dict) -> Observation:
    rlb_obs = Observation(*([None] * 30))
    K = obs["K"]
    points = pointcloud_from_depth(
        obs["depth"], fx=K[0, 0], fy=K[1, 1], cx=K[0, 2], cy=K[1, 2])
    pshape = points.shape
    points = trimesh.transform_points(
        np.reshape(points, (-1, 3)), obs["T_camera_in_link0"])
    points = np.reshape(points, pshape)
    rgb = obs["rgb"]
    rlb_obs.front_point_cloud = points
    rlb_obs.front_rgb = rgb
    rlb_obs.gripper_open = obs['gripper_open']
    rlb_obs.gripper_joint_positions = obs['joint_positions'][-2:]
    rlb_obs.joint_positions = obs['joint_positions'][:-2]
    rlb_obs.joint_velocities = obs['joint_velocites'][:-2]
    gripper_q = R.from_matrix(obs['T_ee_in_link0'][:3, :3]).as_quat()
    rlb_obs.gripper_pose = np.concatenate(
        [obs['T_ee_in_link0'][:3, 3], gripper_q])
    rlb_obs.misc = {
        'front_camera_extrinsics': obs['T_camera_in_link0'],
        'front_camera_intrinsics': obs['K']
    }
    return rlb_obs


class StaticDict:.























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    def __init__(self, value):
        self._value = value

    def get(self, key, default=None):
        return self._value


class MessageSubscriber:
    def __init__(self, topics, callback=None, approx_time_sync=True):
        self._topics = topics  # [(topic_name, topic_msg), ...]
        self._subscribers = []
        self._approx_time_sync = approx_time_sync
        self.msgs = None
        self.callback = callback

    def subscribe(self):
        subscribers = []
        for topic_name, topic_msg in self._topics:
            sub = message_filters.Subscriber(
                topic_name, topic_msg, queue_size=1, buff_size=2 ** 24
            )
            subscribers.append(sub)
        self._subscribers = subscribers

        if self._approx_time_sync:
            sync = message_filters.ApproximateTimeSynchronizer(
                self._subscribers,
                slop=0.1,
                queue_size=50,
            )
        else:
            sync = message_filters.TimeSynchronizer(
                self._subscribers,
                queue_size=100,
            )
        sync.registerCallback(self._callback)

    def unsubscribe(self):
        for sub in self._subscribers:
            sub.unregister()
        self._subscribers = []

    def _callback(self, *msgs):
        self.msgs = msgs
        if self.callback:
            self.callback(*msgs)