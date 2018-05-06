/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#ifndef ISC_GEOMETRY_POINT_H
#define ISC_GEOMETRY_POINT_H

//TODO: airfield20 This class should be templated!

#include <cmath>
#include <cfloat>
#include <string>

namespace ISC {
    namespace geometry {
        class Point2D {
        public:

            /**
             * @brief Defualt Point2D constructor. Values will be initialized to zero
             */
            Point2D();

            /**
             * @brief Point2D constructor with x, y value initialization
             * @param x_in double representing x coordinate
             * @param y_in double representing y coordinate
             */
            Point2D(const double &x_in, const double &y_in);

            /**
             * @return x value of the point as a double
             */
            double get_x() const;

            /**
             * @return y value of point as double
             */
            double get_y() const;

            /**
             * @brief resets the x and y values to new x/y positions being passed in
             * @param new_x_pos Points x value will be set to this
             * @param new_y_pos Points y value will be set to this
             */
            void move(const double &new_x_pos, const double &new_y_pos);

        private:
            double m_x;
            double m_y;
        };

        /**
         * @brief returns true is points are within threshold value
         *
         * The purpose of this function is to give the ability to compare points that represent sensor readings
            * No two sensor readings will be the same in continuous space therefore this thresholding function is necesary
            * to compare points that are equal....but not quite
         *
         * @param p1 first ponit to compare
         * @param p2 second point to compare
         * @param threshold p1 and p2 must be within this value for them to be considered equal
         * @return true is difference between points is less than threshold. Otherwise, false
         */
        bool close_enough(const Point2D &p1, const Point2D &p2, const double &threshold);

        /**
         * @brief distance between two points
         * @param p1 first point
         * @param p2 second point
         * @return double representing the distance between the two points
         */
        double distance(const Point2D &p1, const Point2D &p2);
    }
}

#endif
