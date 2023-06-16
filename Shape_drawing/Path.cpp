#include "Path.h"

void Path::printPath() {
    std::cout << "Path:";
    for (const auto& point : points) {
        std::cout << " (" << point.x << "," << point.y << ")";
    }
    std::cout << std::endl;
}

void Path::clearPath() {
    points.clear();
}

std::vector<int> Path::getXPoints(){
    std::vector<int> xPoints;
    for (const auto& point : points) {
        xPoints.push_back(point.x);
    }
    return xPoints;
}

std::vector<int> Path::getYPoints() {
    std::vector<int> yPoints;
    for (const auto& point : points) {
        yPoints.push_back(point.y);
    }
    return yPoints;
}

void Path::addPointIfNotDuplicate(SDL_Point point) {
    // Check if the path is empty or if the new point is different from the previous point
    if (points.empty() || point.x != points.back().x || point.y != points.back().y) {
        // Point is not a duplicate, add it to the path
        points.push_back(point);
    }
}

std::vector<SDL_Point>& Path::getPoints() {
    return points;
}

std::vector<double> Path::getXPointsAsDouble() {
    std::vector<double> xPointsDouble;
    for (const auto& point : points) {
        xPointsDouble.push_back(static_cast<double>(point.x));
    }
    return xPointsDouble;
}

std::vector<double> Path::getYPointsAsDouble() {
    std::vector<double> yPointsDouble;
    for (const auto& point : points) {
        yPointsDouble.push_back(static_cast<double>(point.y));
    }
    return yPointsDouble;
}
