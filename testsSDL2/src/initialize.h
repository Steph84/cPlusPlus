#ifndef INITIALIZE
#define INITIALIZE

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Initialize
{
	public:
	
	Initialize();
	void InitializeWindow(SDL_Window* window, int WINDOW_WIDTH, int WINDOW_HEIGHT);

};
#endif