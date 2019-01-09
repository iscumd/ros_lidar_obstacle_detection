# Install script for directory: /home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so.0.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/liblidar_obstacle_detection.so.0.0.1"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/liblidar_obstacle_detection.so.0"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/liblidar_obstacle_detection.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so.0.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblidar_obstacle_detection.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/include/boundary.h"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/include/lidar_obstacle_detection.h"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/include/obstacle.h"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/include/point2d.h"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/include/filter.h"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/lidar_obstacle_detection_export.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets.cmake"
         "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/CMakeFiles/Export/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection" TYPE FILE FILES "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/CMakeFiles/Export/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection" TYPE FILE FILES "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/CMakeFiles/Export/lib/cmake/lidar_obstacle_detection/lidar_obstacle_detectionTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/lidar_obstacle_detection" TYPE FILE FILES
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/lib/lidar_obstacle_detection/cmake/lidar_obstacle_detectionConfig.cmake"
    "/home/aaron/yeti_ws/src/obstacle_detection/ros_lidar_obstacle_detection/cmake-build-debug/lib/lidar_obstacle_detection/lidar_obstacle_detection/lidar_obstacle_detectionConfigVersion.cmake"
    )
endif()

