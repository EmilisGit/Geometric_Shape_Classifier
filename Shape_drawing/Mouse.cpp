#include "Mouse.h"
Uint32 Mouse::getMouseState(int& x, int& y) {
	return SDL_GetMouseState(&x, &y);
};
