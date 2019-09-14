#include "initialize.h"

int Initialize::InitializeSDL()
{
	if(SDL_Init(initSDLFlags) < 0)
	{
		printf("Failed to initialize SDL\n");
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return -1;
	}
	else { return 0; }
}

int Initialize::CreateWindow()
{
	window = SDL_CreateWindow(windowTitle, windowXPos, windowYPos, windowWidth, windowHeight, windowFlags);
	if (window == nullptr)	
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}
	else { return 0; }
}

int Initialize::CreateRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	if(renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;	
	}
	else { return 0; }
}