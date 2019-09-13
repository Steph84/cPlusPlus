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
	const char* pathFileName = "./data/background.png";
	background = LoadSurface(pathFileName); // use RAM
	
	pathFileName = "./data/heros.png";
	hero = LoadSurface(pathFileName); // use RAM
	delete pathFileName;
}

// pass file name by reference for memory
SDL_Surface* GameRun::LoadSurface(const char* &pathFileName)
{   
	return IMG_Load(pathFileName);
}