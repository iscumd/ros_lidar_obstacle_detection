//
// Created by aaron on 24/02/18.
//

#include "point.h"

namespace ISC{
    namespace geometry {
        Point2D::Point2D() : m_x(0), m_y(0) {}

        Point2D::Point2D(const double &x_in, const double &y_in) : m_x(x_in), m_y(y_in) {}

        geometry_msgs::Point Point2D::to_ros_point() const {
            geometry_msgs::Point return_point;
            return_point.x = m_x;
            return_point.y = m_y;
            return_point.z = 0;
            return return_point;
        }

        double Point2D::x() const {
            return m_x;
        }

        double Point2D::y() const {
            return m_y;
        }

        void Point2D::move(const double &new_x_pos, const double &new_y_pos) {
            m_x = new_x_pos;
            m_y = new_y_pos;
        }

        bool close_enough(Point2D p1, Point2D p2, double threshold = 1e-2) {
            return (p1.x() - p2.x() < threshold && p1.y() - p2.y() < threshold);
        }
    }
}