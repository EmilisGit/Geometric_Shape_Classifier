#include "Drawing.h"

Drawing::Drawing(SDL_Window* win, SDL_Renderer* rend, Path p)
	: window(win), renderer(rend), path(p) {}

/* @brief Creates mouse path and draws it to the screen when left mouse button is pressed.
* @param mouse object
* @param path object
*/
void Drawing::drawMousePath(Mouse& mouse, Path& path) {
	if (mouse.getMousedown())
	{
		// Get the current mouse position
		int mouseX, mouseY;
		mouse.getMouseState(mouseX, mouseY);
		// Create a new point
		SDL_Point newPoint = { mouseX, mouseY };

		// Add the new point to the path if it's not a duplicate
		path.addPointIfNotDuplicate(newPoint);
		// Render the path
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		const auto& points = path.getPoints();
		if (points.size() > 1) {
			for (size_t i = 1; i < points.size(); i++) {
				const auto& prevPoint = points[i - 1];
				const auto& currPoint = points[i];
				SDL_RenderDrawLine(renderer, prevPoint.x, prevPoint.y, currPoint.x, currPoint.y);
			}
		}
	}
}



