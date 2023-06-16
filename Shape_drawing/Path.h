#pragma once
#include <vector>
#include <SDL.h>
#include <iostream>

/**
 * @class Path
 * @brief Represents a path consisting of SDL points
 */
class Path {
private:
    std::vector<SDL_Point> points; ///< Vector of SDL points representing the path

public:
    /**
     * @brief Default constructor for the Path class
     */
    Path() {};

    /**
     * @brief Getter for the points vector
     * @return Reference to the vector of SDL points
     */
    std::vector<SDL_Point>& getPoints();

    /**
     * @brief Prints the path
     */
    void printPath();

    /**
     * @brief Clears the path by removing all points
     */
    void clearPath();

    /**
     * @brief Retrieves the x-coordinates of the points
     * @return Vector of x-coordinates
     */
    std::vector<int> getXPoints();

    /**
     * @brief Retrieves the y-coordinates of the points
     * @return Vector of y-coordinates
     */
    std::vector<int> getYPoints();

    /**
     * @brief Adds a point to the path if it is not a duplicate
     * @param point SDL point to be added
     */
    void addPointIfNotDuplicate(SDL_Point point);

    /**
     * @brief Retrieves the x-coordinates of the points as double values
     * @return Vector of x-coordinates as double
     */
    std::vector<double> getXPointsAsDouble();

    /**
     * @brief Retrieves the y-coordinates of the points as double values
     * @return Vector of y-coordinates as double
     */
    std::vector<double> getYPointsAsDouble();
};
