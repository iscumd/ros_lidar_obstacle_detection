/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#include "point2d.h"

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

        double Point2D::get_x() const {
            return m_x;
        }

        double Point2D::get_y() const {
            return m_y;
        }

        void Point2D::move(const double &new_x_pos, const double &new_y_pos) {
            m_x = new_x_pos;
            m_y = new_y_pos;
        }

        bool close_enough(const Point2D &p1, const Point2D &p2, const double &threshold = 1e-2) {
            return (p1.get_x() - p2.get_x() < threshold && p1.get_y() - p2.get_y() < threshold);
        }
    }
}
