//TODO: stuff

std::vector<geometry::Point2D> lidar_obstacle_detection::filter_by_boundary(const RectangleBoundary& bound) const {
    std::vector<Point2D> filtered;
    for (auto & pnt : lidarPoints) {
        if (bound->isInside(pnt)) {
            filtered.push_back(pnt);
        }
    }
    return filtered;
}
