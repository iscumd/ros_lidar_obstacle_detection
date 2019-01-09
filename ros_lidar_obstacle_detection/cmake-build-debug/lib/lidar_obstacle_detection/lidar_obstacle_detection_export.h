
#ifndef LIDAR_OBSTACLE_DETECTION_EXPORT_H
#define LIDAR_OBSTACLE_DETECTION_EXPORT_H

#ifdef LIDAR_OBSTACLE_DETECTION_STATIC_DEFINE
#  define LIDAR_OBSTACLE_DETECTION_EXPORT
#  define LIDAR_OBSTACLE_DETECTION_NO_EXPORT
#else
#  ifndef LIDAR_OBSTACLE_DETECTION_EXPORT
#    ifdef lidar_obstacle_detection_EXPORTS
        /* We are building this library */
#      define LIDAR_OBSTACLE_DETECTION_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define LIDAR_OBSTACLE_DETECTION_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef LIDAR_OBSTACLE_DETECTION_NO_EXPORT
#    define LIDAR_OBSTACLE_DETECTION_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef LIDAR_OBSTACLE_DETECTION_DEPRECATED
#  define LIDAR_OBSTACLE_DETECTION_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LIDAR_OBSTACLE_DETECTION_DEPRECATED_EXPORT
#  define LIDAR_OBSTACLE_DETECTION_DEPRECATED_EXPORT LIDAR_OBSTACLE_DETECTION_EXPORT LIDAR_OBSTACLE_DETECTION_DEPRECATED
#endif

#ifndef LIDAR_OBSTACLE_DETECTION_DEPRECATED_NO_EXPORT
#  define LIDAR_OBSTACLE_DETECTION_DEPRECATED_NO_EXPORT LIDAR_OBSTACLE_DETECTION_NO_EXPORT LIDAR_OBSTACLE_DETECTION_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIDAR_OBSTACLE_DETECTION_NO_DEPRECATED
#    define LIDAR_OBSTACLE_DETECTION_NO_DEPRECATED
#  endif
#endif

#endif
