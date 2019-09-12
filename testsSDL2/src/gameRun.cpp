#include <stdio.h>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameRun.h"

using namespace std;

GameRun::GameRun()
{
	// creer le pathFileName ici, le passer en référence puis libérer la mémoire

	// initialize other objects
	background = LoadSurface("background.png"); // use RAM
	hero = LoadSurface("heros.png"); // use RAM
}

SDL_Surface* GameRun::LoadSurface(string fileName)
{
	string pathFileName = "./data/" + fileName;
	return IMG_Load(pathFileName.c_str());
}

// SDL_Surface* GameRun::LoadSurface(string fileName)
// {
// 	string pathFileName = "./data/" + fileName;
// 	SDL_Surface* surface = IMG_Load(pathFileName.c_str());
// 	if(surface == nullptr)
// 	{
// 		SDL_Log("Could not create a surface: %s", SDL_GetError());
// 		return nullptr;	
// 	}
// 	else
// 	{
// 		return surface;
// 	}
// }