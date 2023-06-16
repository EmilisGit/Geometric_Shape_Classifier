/**
 * @file main.cpp
 * @brief Main entry point of the application
 * 
 * Emilis Silingas
 * 2023-06-15
 * Kursinis darbas
 */

#include <SDL.h>
#include "Render_window.h"
#include <iostream>
#include <vector>
#include "Mouse.h"
#include "Drawing.h"
#include "Path.h"
#include "PredictionModel.h"

 /**
  * @brief Main entry point of the application
  * @param argc Number of command line arguments
  * @param args Array of command line argument strings
  * @return The exit status code
  */
int main(int argc, char* args[])
{
    /* Create a Mouse object to handle the input of the mouse */
    Mouse mouse;

    /* Create a vector of vectors of SDL_Points to store the paths */
    Path path;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "Failed to create window " << SDL_GetError() << std::endl;

    /* Create a window */
    Render_window window("Shapes v1.0", 1280, 720);
    bool programRunning = true;
    SDL_Event event;

    /* Create the Drawing object */
    Drawing draw(window.getWindow(), window.getRenderer(), path);

    /* Main loop */
    while (programRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                programRunning = false;
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                /* Setting mouse button states for controlling functions */
                mouse.setMousedown(true);
                mouse.setLeftButtonPressed(true);
                mouse.setLeftButtonReleased(false);
                path.clearPath();
            }
            else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                mouse.setMousedown(false);
                mouse.setLeftButtonPressed(false);
                mouse.setLeftButtonReleased(true);
            }
        }
        /* Color pixels white when left mouse button is pressed */
        draw.drawMousePath(mouse, path);

        /* Run the prediction model */
        if (mouse.getLeftButtonReleased())
        {
            /*For testing purposes
            path.printPath();
            */
            PredictionModel model;
            model.RunModel(path);
            mouse.setLeftButtonReleased(false);
        }
        SDL_RenderPresent(window.getRenderer());
    }

    window.cleanUp();
    return 0;
}
