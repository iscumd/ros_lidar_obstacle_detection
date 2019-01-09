#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ISC::lidar_obstacle_detection" for configuration "Debug"
set_property(TARGET ISC::lidar_obstacle_detection APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ISC::lidar_obstacle_detection PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/liblidar_obstacle_detection.so.0.0.1"
  IMPORTED_SONAME_DEBUG "liblidar_obstacle_detection.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS ISC::lidar_obstacle_detection )
list(APPEND _IMPORT_CHECK_FILES_FOR_ISC::lidar_obstacle_detection "${_IMPORT_PREFIX}/lib/liblidar_obstacle_detection.so.0.0.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
