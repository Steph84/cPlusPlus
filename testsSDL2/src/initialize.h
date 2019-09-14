#ifndef INITIALIZE
#define INITIALIZE

#include <SDL2/SDL.h>
#include <stdio.h>

class Initialize
{
private:
	int InitializeSDL();
	int CreateWindow();
	int CreateRenderer();
	
	const Uint32 initSDLFlags = SDL_INIT_VIDEO;
	const char* windowTitle = "SDL2 tests";
	const int windowWidth = 1200;
	const int windowHeight = 200;
	const int windowXPos = SDL_WINDOWPOS_UNDEFINED;
	const int windowYPos = SDL_WINDOWPOS_UNDEFINED;
	const Uint32 windowFlags = SDL_WINDOW_SHOWN;
	const Uint32 rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

public:
	Initialize();

	int initIndex;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif