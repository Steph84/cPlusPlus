#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "initialize.h"

using namespace std;

// constructor
Initialize::Initialize()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL\n");
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return -1;
	}
}

void Initialize::InitializeWindow(SDL_Window* window, int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
	// create window
	window = SDL_CreateWindow("SDL2 tests", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)	
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}
}