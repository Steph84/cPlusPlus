#ifndef INITIALIZE
#define INITIALIZE

#include <SDL2/SDL.h>
#include <stdio.h>

class Initialize
{
public:

	int InitializeSDL();
	int CreateWindow();
	// int CreateRenderer();

	SDL_Window* window;
};
#endif