#include "gameRun.h"

GameRun::GameRun()
{
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