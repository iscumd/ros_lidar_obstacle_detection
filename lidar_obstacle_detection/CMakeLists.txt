cmake_minimum_required(VERSION 2.8.3)
project(obstacle_detection)

set(CMAKE_CXX_STANDARD 11)

include(GenerateExportHeader)

set( PROJECT_NAME lidar_obstacle_detection )

set(PROJECT_VERSION 0.0.1)

set( SRC_FILES
        src/boundary.cpp
        src/lidar_obstacle_detection.cpp
        src/obstacle.cpp
        src/point2d.cpp )

add_library( ${PROJECT_NAME} SHARED ${SRC_FILES} )
add_library( ISC::${PROJECT_NAME} ALIAS ${PROJECT_NAME} )

target_include_directories( ${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            src
)

generate_export_header( ${PROJECT_NAME} )

set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION ${PROJECT_VERSION})

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

install(
        FILES
            include/boundary.h
            include/lidar_obstacle_detection.h
            include/obstacle.h
            include/point2d.h
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_export.h"
        DESTINATION
            include
        COMPONENT
            Devel
)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/catch)
set("TEST_LIB_${PROJECT_NAME}" "Catch_${PROJECT_NAME}")
add_library("TEST_LIB_${PROJECT_NAME}" INTERFACE)
target_include_directories("TEST_LIB_${PROJECT_NAME}" INTERFACE ${CATCH_INCLUDE_DIR})

file(GLOB_RECURSE TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
set(TEST_EXECUTABLE "${PROJECT_NAME}_TESTS")
add_executable(${TEST_EXECUTABLE} ${TEST_FILES})
target_link_libraries(${TEST_EXECUTABLE} PRIVATE "TEST_LIB_${PROJECT_NAME}" ${PROJECT_NAME})