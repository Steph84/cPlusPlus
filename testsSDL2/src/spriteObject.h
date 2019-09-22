#ifndef SPRITEOBJECT
#define SPRITEOBJECT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

using namespace std;

class SpriteObject
{
private:
	string pathData = "./data/";

public:
	SpriteObject();
	SpriteObject* SpriteObjectCreation(string &pFileName, int pScale);

	int id;
	string fileName;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	int scale;
};
#endif