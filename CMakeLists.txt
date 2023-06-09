PROJECT(multisearch_sim)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)

SET(CMAKE_CXX_FLAGS "-march=native -Wall -Werror -g -Wno-unused-function")
set(CMAKE_CXX_STANDARD 14)

IF(${CMAKE_BUILD_TYPE} MATCHES "Release")
  MESSAGE(STATUS "Additional Flags for Release mode")
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fopenmp -fno-builtin-malloc \
      -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free -O3 -DNDEBUG")
  SET(BUILD_SPECIFIC_LIBRARIES "tcmalloc")
ELSEIF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
  MESSAGE(STATUS "Additional Flags for Debug mode")
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
  SET(BUILD_SPECIFIC_LIBRARIES "")
ENDIF()

MESSAGE(STATUS "SOURCE DIR: ${PROJECT_SOURCE_DIR}")

# Qt setup (needs to precede executable)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_INCLUDE_CURRENT_DIR on)
find_package(Qt5 COMPONENTS Core Widgets WebSockets REQUIRED)

FIND_PACKAGE(Lua51 REQUIRED)
FIND_PACKAGE(Eigen3 REQUIRED)
FIND_PACKAGE(Ceres REQUIRED)

INCLUDE($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
ROSBUILD_INIT()
SET(ROS_BUILD_STATIC_LIBS true)
SET(ROS_BUILD_SHARED_LIBS false)

LIST(APPEND CMAKE_PREFIX_PATH "/opt/libtorch")
FIND_PACKAGE(OpenCV REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(catkin REQUIRED COMPONENTS
      cv_bridge
      roscpp
      image_transport
)


SET(libs roslib roscpp rosbag glog gflags amrl_shared_lib boost_system lua5.1
    pthread image_transport cv_bridge)

# ADD_LIBRARY(shared_library
#             graph_navigation/src/visualization/visualization.cc
#             graph_navigation/src/vector_map/vector_map.cc)
# rg 3 previous lines
ADD_SUBDIRECTORY(amrl_shared_lib)
# ADD_SUBDIRECTORY(graph_navigation/src/shared)
# INCLUDE_DIRECTORIES(graph_navigation/src/shared)
INCLUDE_DIRECTORIES(amrl_shared_lib)
INCLUDE_DIRECTORIES(config-reader/include)
# INCLUDE_DIRECTORIES(graph_navigation/src/third_party)
# INCLUDE_DIRECTORIES(graph_navigation/src)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

ROSBUILD_GENMSG()
ROSBUILD_GENSRV()

MESSAGE(STATUS "Includes: ${INCLUDE_DIRECTORIES}")


# ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/enml/src/shared)
 ROSBUILD_ADD_EXECUTABLE(enml_tbot
     enml/src/non_markov_localization_main_tbot.cpp
     enml/src/non_markov_localization.cpp
     enml/src/kdtree.cpp
     enml/src/perception_2d.cpp
     enml/src/vector_map/vector_map.cc
     enml/src/visualization/visualization.cc
     enml/src/visualization/gui_helpers.cc)
 TARGET_INCLUDE_DIRECTORIES(enml_tbot PRIVATE
     amrl_shared_lib
     config-reader/include
     enml/src
     enml/src/shared
     enml/src/config-reader/include
     ${LUA_INCLUDE_DIR}
     ${CERES_INCLUDE_DIRS})
 ADD_DEPENDENCIES(enml_tbot rosbuild_precompile)
 TARGET_LINK_LIBRARIES(enml_tbot ceres roslib roscpp ncurses pthread boost_system
     ${LUA_LIBRARIES} rt popt glog rosbag amrl_shared_lib
     ${BUILD_SPECIFIC_LIBRARIES})

 ROSBUILD_ADD_EXECUTABLE(enml
     enml/src/non_markov_localization_main.cpp
     enml/src/non_markov_localization.cpp
     enml/src/kdtree.cpp
     enml/src/perception_2d.cpp
     enml/src/vector_map/vector_map.cc
     enml/src/visualization/visualization.cc
     enml/src/visualization/gui_helpers.cc)
 TARGET_INCLUDE_DIRECTORIES(enml PRIVATE
     amrl_shared_lib
     config-reader/include
     enml/src
     enml/src/shared
     enml/src/config-reader/include
     ${LUA_INCLUDE_DIR}
     ${CERES_INCLUDE_DIRS})
 ADD_DEPENDENCIES(enml rosbuild_precompile)
 TARGET_LINK_LIBRARIES(enml ceres roslib roscpp ncurses pthread boost_system
     ${LUA_LIBRARIES} rt popt glog rosbag amrl_shared_lib
     ${BUILD_SPECIFIC_LIBRARIES})



