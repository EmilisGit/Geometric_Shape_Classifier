#pragma once

#include <SDL.h>
#include <vector>
#include "Mouse.h"
#include "Render_window.h"
#include "Path.h"

/**
 * @class Drawing
 * @brief Handles the drawing on the window
 */
class Drawing {
private:
    SDL_Window* window; ///< Pointer to the SDL window
    SDL_Renderer* renderer; ///< Pointer to the SDL renderer
    Path path; ///< Path object to store the drawing

public:
    /**
     * @brief Constructor for the Drawing class
     * @param win Pointer to the SDL window
     * @param rend Pointer to the SDL renderer
     * @param p Path object to store the drawing
     */
    Drawing(SDL_Window* win, SDL_Renderer* rend, Path p);

    /**
     * @brief Handles the mouse down event
     * @param mouse Reference to the Mouse object
     * @param path Reference to the Path object
     */
    void drawMousePath(Mouse& mouse, Path& path);
};
