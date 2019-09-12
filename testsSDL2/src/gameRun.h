#ifndef GAMERUN
#define GAMERUN

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class GameRun
{
	public:
	
	GameRun();
	SDL_Surface* LoadSurface(string fileName);
	
	SDL_Surface* background;
	SDL_Surface* hero;
	
	// int InitializeWindow(SDL_Window* window, int WINDOW_WIDTH, int WINDOW_HEIGHT);

};
#endif