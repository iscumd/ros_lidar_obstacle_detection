//
// Created by aaron on 24/02/18.
//

#include "obstacle.h"

namespace ISC {
    namespace geometry {
        Obstacle2D::Obstacle2D() : m_position(Point2D()), m_interior_points({}), m_size(0),
                                   m_type(ObstacleType::UNKNOWN) {}

        Obstacle2D::Obstacle2D(const Point2D &position, const double &size, const ObstacleType &type) : m_position(
                position), m_interior_points({}), m_size(size), m_type(type) {}

        Obstacle2D::Obstacle2D(const Point2D &position, const double &size, const ObstacleType &type,
                               std::vector<Point2D> interior_points) : m_position(
                position), m_interior_points(interior_points), m_size(size), m_type(type) {}

        std::vector<Point2D> Obstacle2D::interior_points() const {
            return m_interior_points;
        }

        Point2D Obstacle2D::position() const {
            return m_position;
        }

        double Obstacle2D::size() const {
            return m_size;
        }

        ObstacleType Obstacle2D::type() const {
            return m_type;
        }

        void Obstacle2D::set_interior_points(const std::vector<Point2D> interior_points) {
            m_interior_points = interior_points;
        }

        void Obstacle2D::set_position(const Point2D &position) {
            m_position = position;
        }

        void Obstacle2D::set_size(const double &size) {
            m_size = size;
        }

        void Obstacle2D::set_type(const ObstacleType &type) {
            m_type = type;
        }

    }
}