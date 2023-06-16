#pragma once
#include <SDL.h>

class Render_window
{
protected:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Render_window();
	Render_window(const char* p_title, int p_w, int p_h);
	SDL_Renderer* getRenderer() const {
		return renderer;
	}
	SDL_Window* getWindow() const {
		return window;
	}
	void cleanUp(); 
};