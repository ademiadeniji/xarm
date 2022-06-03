# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from xarm_msgs/RobotMsg.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class RobotMsg(genpy.Message):
  _md5sum = "b796af25d2a8912964fb162d2141ac39"
  _type = "xarm_msgs/RobotMsg"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """# feedback information of the controlled robot
Header header

# state of robot:
#	1: RUNNING, executing motion command.
#	2: SLEEPING, not in execution, but ready to move.
#	3: PAUSED, paused in the middle of unfinished motion.
#	4: STOPPED, not ready for any motion commands.
#	5: CONFIG_CHANGED, system configuration or mode changed, not ready for motion commands.
int16 state

# mode of robot:
#	0 for POSITION mode.(position control by xarm controller box, execute api standard commands)
#	1 for SERVOJ mode. (Immediate execution towards received joint space target, like a step response)
#	2 for TEACHING_JOINT mode. (Gravity compensated mode, easy for teaching)
int16 mode

# cmdnum: number of commands waiting in the buffer.
int16 cmdnum

# mt_brake: if translated to binary digits, each bit represent one axis, 1 for brake enabled, 0 for brake disabled
int16 mt_brake

# mt_able: if translated to binary digits, each bit represent one axis, 1 for servo control enabled, 0 for servo disabled
int16 mt_able

# error code (if non-zero)
int16 err

# warning code (if non-zero)
int16 warn

# current joint angles expressed in radian.
float32[] angle

# current TCP Cartesian position expressed in mm(position), radian(orientation)  
float32[6] pose

# TCP offset from center of flange, with respect to tool frame.
float32[6] offset
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
"""
  __slots__ = ['header','state','mode','cmdnum','mt_brake','mt_able','err','warn','angle','pose','offset']
  _slot_types = ['std_msgs/Header','int16','int16','int16','int16','int16','int16','int16','float32[]','float32[6]','float32[6]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,state,mode,cmdnum,mt_brake,mt_able,err,warn,angle,pose,offset

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(RobotMsg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.state is None:
        self.state = 0
      if self.mode is None:
        self.mode = 0
      if self.cmdnum is None:
        self.cmdnum = 0
      if self.mt_brake is None:
        self.mt_brake = 0
      if self.mt_able is None:
        self.mt_able = 0
      if self.err is None:
        self.err = 0
      if self.warn is None:
        self.warn = 0
      if self.angle is None:
        self.angle = []
      if self.pose is None:
        self.pose = [0.] * 6
      if self.offset is None:
        self.offset = [0.] * 6
    else:
      self.header = std_msgs.msg.Header()
      self.state = 0
      self.mode = 0
      self.cmdnum = 0
      self.mt_brake = 0
      self.mt_able = 0
      self.err = 0
      self.warn = 0
      self.angle = []
      self.pose = [0.] * 6
      self.offset = [0.] * 6

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7h().pack(_x.state, _x.mode, _x.cmdnum, _x.mt_brake, _x.mt_able, _x.err, _x.warn))
      length = len(self.angle)
      buff.write(_struct_I.pack(length))
      pattern = '<%sf'%length
      buff.write(struct.Struct(pattern).pack(*self.angle))
      buff.write(_get_struct_6f().pack(*self.pose))
      buff.write(_get_struct_6f().pack(*self.offset))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 14
      (_x.state, _x.mode, _x.cmdnum, _x.mt_brake, _x.mt_able, _x.err, _x.warn,) = _get_struct_7h().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sf'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.angle = s.unpack(str[start:end])
      start = end
      end += 24
      self.pose = _get_struct_6f().unpack(str[start:end])
      start = end
      end += 24
      self.offset = _get_struct_6f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7h().pack(_x.state, _x.mode, _x.cmdnum, _x.mt_brake, _x.mt_able, _x.err, _x.warn))
      length = len(self.angle)
      buff.write(_struct_I.pack(length))
      pattern = '<%sf'%length
      buff.write(self.angle.tostring())
      buff.write(self.pose.tostring())
      buff.write(self.offset.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 14
      (_x.state, _x.mode, _x.cmdnum, _x.mt_brake, _x.mt_able, _x.err, _x.warn,) = _get_struct_7h().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sf'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.angle = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=length)
      start = end
      end += 24
      self.pose = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=6)
      start = end
      end += 24
      self.offset = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=6)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_6f = None
def _get_struct_6f():
    global _struct_6f
    if _struct_6f is None:
        _struct_6f = struct.Struct("<6f")
    return _struct_6f
_struct_7h = None
def _get_struct_7h():
    global _struct_7h
    if _struct_7h is None:
        _struct_7h = struct.Struct("<7h")
    return _struct_7h