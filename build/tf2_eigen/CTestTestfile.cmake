# CMake generated Testfile for 
# Source directory: /home/stepjam/catkin_ws/src/geometry2/tf2_eigen
# Build directory: /home/stepjam/catkin_ws/build/tf2_eigen
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_tf2_eigen_gtest_tf2_eigen-test "/home/stepjam/catkin_ws/build/tf2_eigen/catkin_generated/env_cached.sh" "/home/stepjam/miniconda/envs/py37/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/stepjam/catkin_ws/build/tf2_eigen/test_results/tf2_eigen/gtest-tf2_eigen-test.xml" "--return-code" "/home/stepjam/catkin_ws/devel/lib/tf2_eigen/tf2_eigen-test --gtest_output=xml:/home/stepjam/catkin_ws/build/tf2_eigen/test_results/tf2_eigen/gtest-tf2_eigen-test.xml")
set_tests_properties(_ctest_tf2_eigen_gtest_tf2_eigen-test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/kinetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/kinetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/kinetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/stepjam/catkin_ws/src/geometry2/tf2_eigen/CMakeLists.txt;41;catkin_add_gtest;/home/stepjam/catkin_ws/src/geometry2/tf2_eigen/CMakeLists.txt;0;")
subdirs("gtest")
