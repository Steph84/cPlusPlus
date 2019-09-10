#include <stdio.h>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameRun.h"

using namespace std;

GameRun::GameRun()
{
	// initialize other objects
	SDL_Surface* background = nullptr; // use RAM
	SDL_Surface* hero = nullptr; // use RAM

	background = LoadSurface("background.png");
	hero = LoadSurface("heros.png");

}

SDL_Surface* GameRun::LoadSurface(string fileName)
{
	string pathFileName = "./data/" + fileName;
	SDL_Surface* surface = IMG_Load(pathFileName.c_str());
	if(surface == nullptr)
	{
		SDL_Log("Could not create a surface: %s", SDL_GetError());
		return nullptr;	
	}
	else
	{
		return surface;
	}
}