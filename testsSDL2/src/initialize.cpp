#include "initialize.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 200;

int Initialize::InitializeSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL\n");
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return -1;
	}
	else
	{
		return 0;
	}
}

int Initialize::CreateWindow()
{
	window = SDL_CreateWindow("SDL2 tests", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)	
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}
	else
	{
		return 0;
	}
}