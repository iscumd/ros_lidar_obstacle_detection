/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#include "point2d.h"
#include <stdexcept>

namespace ISC
{
namespace geometry
{
    Point2D::Point2D()
        : m_x( 0 )
        , m_y( 0 )
    {
    }

    Point2D::Point2D( const double& x_in, const double& y_in )
        : m_x( x_in )
        , m_y( y_in )
    {

        if ( x_in >= DBL_MAX || y_in >= DBL_MAX )
        {
            throw std::runtime_error( "x input and y input must be finite values within "
                                      "the range of the double type" );
        }
        if ( x_in != 0.0 && x_in <= -DBL_MAX )
        {
            throw std::runtime_error(
                "x input must be a finite value within the range of the double type" );
        }
        if ( y_in != 0.0 && y_in <= -DBL_MAX )
        {
            throw std::runtime_error(
                "y input must be a finite value within the range of the double type" );
        }
    }

    double Point2D::get_x() const { return m_x; }

    double Point2D::get_y() const { return m_y; }

    void Point2D::move( const double& new_x_pos, const double& new_y_pos )
    {

        if ( new_x_pos >= DBL_MAX || new_y_pos >= DBL_MAX )
        {
            throw std::runtime_error( "new x input and y input must be finite values "
                                      "within the range of the double type" );
        }
        if ( new_x_pos != 0.0 && new_x_pos <= -DBL_MAX )
        {
            throw std::runtime_error( "new x input must be a finite value within the "
                                      "range of the double type" );
        }
        if ( new_y_pos != 0.0 && new_y_pos <= -DBL_MAX )
        {
            throw std::runtime_error( "new y input must be a finite value within the "
                                      "range of the double type" );
        }

        m_x = new_x_pos;
        m_y = new_y_pos;
    }

    bool close_enough( const Point2D& p1, const Point2D& p2, const double& threshold )
    {
        return ( std::abs(p1.get_x() - p2.get_x()) < threshold
                 && std::abs(p1.get_y() - p2.get_y()) < threshold );
    }

    double distance( const Point2D& p1, const Point2D& p2 )
    {
        return std::sqrt( std::pow( p1.get_x() - p2.get_x(), 2 )
                          + std::pow( p1.get_y() - p2.get_y(), 2 ) );
    }

    bool operator==( const Point2D& rhs, const Point2D& lhs )
    {
        return ( rhs.get_x() == lhs.get_x() ) && ( rhs.get_y() == lhs.get_y() );
    }
}
}
