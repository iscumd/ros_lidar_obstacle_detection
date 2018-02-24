#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "point.h"

namespace ISC {
    namespace geometry {

        class RectangleBoundary {
        public:
            /**
             * @brief defaullt RectangleBoundary constructor, sets everything to zero
             */
            RectangleBoundary();

            /**
             * @brief Initialized RectangleBoundary constructor
             * @param x_length length of the box in the x dimension
             * @param y_length length of the box in the y dimension
             * @param boundary_position position of the bottom left corner of the box. E.g. the -x and -y corner, third quadrant corner
             */
            RectangleBoundary(const double &x_length, const double &y_length, const Point2D &boundary_position);

            /**
             *
             * @return double representing the length of the RectangleBoundary in the x dimension
             */
            double x_dim() const;

            /**
             *
             * @return double representing the length of the RectangleBoundary in the y dimension
             */
            double y_dim() const;

            /**
             *
             * @return Point2D representing the position of the bottom left corner of the box. E.g. the -x and -y corner, third quadrant corner
             */
            Point2D position() const;

            /**
             * @brief change the position of boundary
             * @param x_length new length of the box in the x dimension
             * @param y_length new length of the box in the y dimension
             * @param boundary_position new position of the bottom left corner of the box. E.g. the -x and -y corner, third quadrant corner
             */
            void reset(const double &x_length, const double &y_length, const Point2D &boundary_position);

            /**
             * @brief get the vertices of all four corners of the RectangleBoundary
             * These values are computed when this function is called
             * @return vector<Point2D> representing vertices of the box, counterclockwise
             */
            std::vector<Point2D> vertices() const;

            /**
             *
             * @return a Point2D object representing the center of the box; This value is computed when calling this function
             */
            Point2D center() const;

        private:
            Point2D m_position;
            double m_x_dim;
            double m_y_dim;
        };
    }
}
#endif
