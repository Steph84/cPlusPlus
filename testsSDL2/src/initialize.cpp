#include "initialize.h"

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