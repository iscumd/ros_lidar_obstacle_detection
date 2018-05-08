/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#include "obstacle.h"

namespace ISC
{
namespace geometry
{
    Obstacle2D::Obstacle2D()
        : m_position( Point2D() )
        , m_interior_points( { {} } )
        , m_size( 0 )
        , m_type( ObstacleType::UNKNOWN )
        , m_polygon( { {} } )
    {
    }

    Obstacle2D::Obstacle2D( const Point2D& position, const double& size,
                            const ObstacleType& type )
        : m_position( position )
        , m_interior_points( {} )
        , m_size( size )
        , m_type( type )
    {
    }

    Obstacle2D::Obstacle2D( const Point2D& position, const double& size,
                            const ObstacleType& type,
                            std::vector<Point2D> interior_points )
        : m_position( position )
        , m_interior_points( interior_points )
        , m_size( size )
        , m_type( type )
    {
    }

    Obstacle2D::Obstacle2D( const Point2D& position, const ObstacleType& type,
                            const std::vector<Point2D>& polygon )
        : m_position( position )
        , m_interior_points( {} )
        , m_size( 0 )
        , m_type( type )
        , m_polygon( polygon )
    {
    }

    std::vector<Point2D> Obstacle2D::get_interior_points() const
    {
        return m_interior_points;
    }

    Point2D Obstacle2D::get_position() const { return m_position; }

    double Obstacle2D::get_size() const { return m_size; }

    ObstacleType Obstacle2D::get_type() const { return m_type; }

    std::vector<Point2D> Obstacle2D::get_polygon() const { return m_polygon; }

    void Obstacle2D::set_interior_points( const std::vector<Point2D>& interior_points )
    {
        m_interior_points = interior_points;
    }

    void Obstacle2D::set_position( const Point2D& position ) { m_position = position; }

    void Obstacle2D::set_size( const double& size ) { m_size = size; }

    void Obstacle2D::set_type( const ObstacleType& type ) { m_type = type; }

    void Obstacle2D::set_polygon( const std::vector<Point2D>& polygon )
    {
        m_polygon = polygon;
    }
}
}
