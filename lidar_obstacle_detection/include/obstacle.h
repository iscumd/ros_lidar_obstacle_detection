/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#ifndef ISC_GEOMETRY_OBSTACLE_H
#define ISC_GEOMETRY_OBSTACLE_H

#include "point2d.h"

#include <vector>

namespace ISC
{
namespace geometry
{
    enum class ObstacleType
    {
        /**
         * Cylindrical obstacle, size represents diameter of the object
         */
        PYLON,
        /**
         * Near cylindrical obstacle, size represents diameter of the object
         */
        BARREL,
        /**
         * Flat Planar object, size represents width
         */
        PLANE,
        // Add new obstacle types here! Dont forget to add comments!
        UNKNOWN
    };

    class Obstacle2D
    {

    public:
        /**
         * @brief Obstacle2D default constructor
         * This will initialize everything using default constructors. Obstacle type is
         * set to UNKNOWN
         */
        Obstacle2D();

        /**
         * @brief initialized Obstacle2D constructor without interior points
         * @param position x,y coordinate representing the position of the obstacle
         * @param size can represent radius or extents of the obstacle
         * @param type the type of obstacle gives indicators as to how the data should be
         * interpreted
         */
        Obstacle2D( const Point2D& position, const double& size,
                    const ObstacleType& type );

        /**
         * @brief initialized Obstacle2D constructor without interior points
         * @param position x,y coordinate representing the position of the obstacle
         * @param size can represent radius or extents of the obstacle
         * @param type the type of obstacle gives indicators as to how the data should be
         * interpreted
         * @param interior_points points that were scanned that make up the obstacle
         */
        Obstacle2D( const Point2D& position, const double& size,
                    const ObstacleType& type, std::vector<Point2D> interior_points );

        /**
         * @brief initialized Obstacle2D constructor without interior points
         * @param position x,y coordinate representing the position of the obstacle
         * @param type the type of obstacle gives indicators as to how the data should be
         * interpreted
         * @param polygon vector representing the concave hull (polygon representation)
         * of the obstacle
         */
        Obstacle2D( const Point2D& position, const ObstacleType& type,
                    const std::vector<Point2D>& polygon );

        /**
         *
         * @return Point2D object representing the coordinates of the center of the
         * obstacle in 2D space
         */
        Point2D get_position() const;

        /**
         *
         * @return ObstacleType represnting the type of obstacle this object is
         * representing
         */
        ObstacleType get_type() const;

        /**
         *
         * @return a vector of points that were scanned in that make up the obstacle
         */
        std::vector<Point2D> get_interior_points() const;

        /**
         *
         * @return a double representing the size of the object. See ObstacleType to
         * interpret this value
         */
        double get_size() const;

        /**
         *
         * @return a vector of points representing an obstacle as a polygon. This member
         * is optional
         */
        std::vector<Point2D> get_polygon() const;

        /**
         *
         * @param position new position of the obstacle
         */
        void set_position( const Point2D& position );

        /**
         *
         * @param size new size of the obstacle
         */
        void set_size( const double& size );

        /**
         *
         * @param interior_points new points for the obstacle
         */
        void set_interior_points( const std::vector<Point2D>& interior_points );

        /**
         *
         * @param type new type to change the obstacle to
         */
        void set_type( const ObstacleType& type );

        /**
         *
         * @param a vector of points representing an obstacle as a polygon. This member
         * is optional
         */
        void set_polygon( const std::vector<Point2D>& polygon );


    private:
        Point2D m_position;
        ObstacleType m_type;
        std::vector<Point2D> m_polygon;
        std::vector<Point2D> m_interior_points;
        double m_size;
    };
}
}

#endif
