//
// Created by aaron on 24/02/18.
//

#include "boundary.h"

namespace ISC
{
namespace geometry
{

    RectangleBoundary::RectangleBoundary()
        : m_position( Point2D() )
        , m_x_dim( 0 )
        , m_y_dim( 0 )
    {
    }

    RectangleBoundary::RectangleBoundary( const double& x_length, const double& y_length,
                                          const Point2D& boundary_position )
        : m_position( boundary_position )
        , m_x_dim( x_length )
        , m_y_dim( y_length )
    {
    }

    double RectangleBoundary::x_dim() const { return m_x_dim; }

    double RectangleBoundary::y_dim() const { return m_y_dim; }

    Point2D RectangleBoundary::position() const { return m_position; }

    void RectangleBoundary::reset( const double& x_length, const double& y_length,
                                   const Point2D& boundary_position )
    {
        m_y_dim    = y_length;
        m_x_dim    = x_length;
        m_position = boundary_position;
    }

    std::vector<Point2D> RectangleBoundary::vertices() const
    {
        return { m_position, Point2D( m_position.get_x() + x_dim(), m_position.get_y() ),
                 Point2D( m_position.get_x() + x_dim(), m_position.get_y() + y_dim() ),
                 Point2D( m_position.get_x(), m_position.get_y() + y_dim() ) };
    }

    Point2D RectangleBoundary::center() const
    {
        return { m_position.get_x() + x_dim() / 2, m_position.get_y() + y_dim() / 2 };
    }

    bool isInside( const Point2D& point, const RectangleBoundary& bound )
    {
        if ( point.get_x() <= bound.position().get_x() )
        {  // point is left of the boundary
            return false;
        }
        else if ( point.get_y() <= bound.position().get_y() )
        {  // point is below the boundary
            return false;
        }
        else if ( point.get_x() >= bound.position().get_x() + bound.x_dim() )
        {  // point is right of the boundary
            return false;
        }
        else if ( point.get_y() >= bound.position().get_y() + bound.y_dim() )
        {  // point is above the boundary
            return false;
        }
        else if(std::isnan(point.get_x()) || std::isnan(point.get_x()))
        {
            return false;
        }
        else
        {
            return true;  //  inside boundary
        }
    }
}  // namespace geometry
}  // namespace ISC
