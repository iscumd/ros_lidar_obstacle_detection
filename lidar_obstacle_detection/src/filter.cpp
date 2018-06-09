//
// Created by aaron on 08/06/18.
//

#include "filter.h"

using ISC::geometry::RectangleBoundary;
using ISC::geometry::Point2D;

namespace ISC
{
namespace filtering
{
    std::vector<Point2D> filter_by_boundary( const RectangleBoundary& bound,
                                             const std::vector<Point2D>& points )
    {
        std::vector<Point2D> filtered;
        for ( const auto& point : points )
        {
            if ( ISC::geometry::isInside( point, bound ) )
            {
                filtered.push_back( point );
            }
        }
        return filtered;
    }
}
}