//
// Created by aaron on 30/06/18.
//

#include "classification.h"

namespace ISC
{
namespace classification
{

    namespace
    {
        Point2D get_median_point( const cluster& clus )
        {
            int middle = static_cast<int>( clus.size() / 2 );
            return clus.at( middle );
        }
        double get_width( const cluster& clus )
        {
            return ISC::geometry::distance( clus.at( 0 ), clus.back() );
        }
    }

    double avg_slope( const cluster& clus )
    {
        double avg = 0;

        for ( int i = 0; i < clus.size() - 1; ++i )
        {
            avg += ( clus.at( i + 1 ).get_y() - clus.at( i ).get_y() )
                / ( clus.at( i + 1 ).get_x() - clus.at( i ).get_x() );
        }

        avg = avg / ( clus.size() - 1 );

        return avg;
    }

    double sum_sqaured_slope_deviation( const cluster& clus )
    {
        double sum = 0;
        double avg = avg_slope( clus );

        for ( int i = 0; i < clus.size() - 1; ++i )
        {
            double slope = ( clus.at( i + 1 ).get_y() - clus.at( i ).get_y() )
                / ( clus.at( i + 1 ).get_x() - clus.at( i ).get_x() );
            double deviation_squared = std::pow( std::abs( avg - slope ), 2 );
            sum += deviation_squared;
        }

        return sum;
    }

    Obstacle2D classify_obstacle( const cluster& clus )
    {
        const int CYLINDER_DEVIATION = 100;
        const int PLANE_DEVIATION    = 0;

        double sssd = sum_sqaured_slope_deviation( clus );

        if ( std::abs( sssd - CYLINDER_DEVIATION ) < std::abs( sssd - PLANE_DEVIATION ) )
        {
            Obstacle2D obs( get_median_point( clus ), get_width( clus ),
                            ISC::geometry::ObstacleType::PYLON, clus );
            return obs;
        }

        else
        {
            Obstacle2D obs( get_median_point( clus ), get_width( clus ),
                            ISC::geometry::ObstacleType::PLANE, clus );
            return obs;
        }
    }
}
}