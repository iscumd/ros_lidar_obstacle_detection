//
// Created by aaron on 24/02/18.
//

#include "boundary.h"

namespace ISC {
    namespace geometry {

        RectangleBoundary::RectangleBoundary() : m_position(Point2D()), m_x_dim(0), m_y_dim(0) {}

        RectangleBoundary::RectangleBoundary(const double &x_length, const double &y_length,
                                             const Point2D &boundary_position) : m_position(boundary_position),
                                                                                 m_x_dim(x_length), m_y_dim(y_length) {}

        double RectangleBoundary::x_dim() const {
            return m_x_dim;
        }

        double RectangleBoundary::y_dim() const {
            return m_y_dim;
        }

        Point2D RectangleBoundary::position() const {
            return m_position;
        }

        void
        RectangleBoundary::reset(const double &x_length, const double &y_length, const Point2D &boundary_position) {
            m_y_dim = y_length;
            m_x_dim = x_length;
            m_position = boundary_position;
        }

        std::vector <Point2D> RectangleBoundary::vertices() const {
            return {
                    m_position,
                    Point2D(m_position.x() + x_dim(), m_position.y()),
                    Point2D(m_position.x() + x_dim(), m_position.y() + y_dim()),
                    Point2D(m_position.x(), m_position.y() + y_dim())
            };
        }

        Point2D RectangleBoundary::center() const {
            return Point2D(m_position.x() + x_dim() / 2, m_position.y() + y_dim() / 2);
        }
    }
}