#include <SDL.h>
#include "Render_window.h"
#include <iostream>

Render_window::Render_window()
{
	window = NULL;
	renderer = NULL;
}
Render_window::Render_window(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == NULL)
	{
		std::cout << "Window failed to create" << SDL_GetError() << std::endl;
	}	
}

void Render_window::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
