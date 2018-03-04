/**
 *  @Author Team Yeti 2018
 */

#include "boundary.h"

namespace ISC {
    namespace geometry {

        RectangleBoundary::RectangleBoundary() : m_position(Point2D()), m_x_dim(0), m_y_dim(0) {}

        RectangleBoundary::RectangleBoundary(const double &x_length, const double &y_length,
                                             const Point2D &boundary_position) : m_position(boundary_position),
                                                                                 m_x_dim(x_length), m_y_dim(y_length) {}

        double RectangleBoundary::get_x_dim() const {
            return m_x_dim;
        }

        double RectangleBoundary::get_y_dim() const {
            return m_y_dim;
        }

        Point2D RectangleBoundary::get_position() const {
            return m_position;
        }

        void RectangleBoundary::reset(const double &x_length, const double &y_length, const Point2D &boundary_position) {
            m_y_dim = y_length;
            m_x_dim = x_length;
            m_position = boundary_position;
        }

        std::vector <Point2D> RectangleBoundary::get_vertices() const {
            return {
                    m_position,
                    Point2D(m_position.get_x() + get_x_dim(), m_position.get_y()),
                    Point2D(m_position.get_x() + get_x_dim(), m_position.get_y() + get_y_dim()),
                    Point2D(m_position.get_x(), m_position.get_y() + get_y_dim())
            };
        }

        Point2D RectangleBoundary::get_center() const {
            return Point2D(m_position.get_x() + get_x_dim() / 2, m_position.get_y() + get_y_dim() / 2);
        }

        // assuming the rectangle is with respect to (-x, -y)
        // on the boundary line itself is considered inside of the boundary
        bool RectangleBoundary::isInside(const Point2D &point) const {
            if(point->get_x() < this.get_position().get_x()) { // point is left of the boundary
                return false;
            } else if (point->get_y() < this.get_position().get_y()) { // point is below the boundary
                return false;
            } else if (point->get_x() > this.get_position().get_x() + this.get_x_dim()) { // point is right of the boundary
                return false;
            } else if (point->get_y() > this.get_position().get_y() + this.get_y_dim()) { // point is above the boundary
                return false;
            } else {
                return true; // on boundary line or inside
            }
        }
        
    }
}
