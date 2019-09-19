#ifndef SPRITEOBJECT
#define SPRITEOBJECT

#include <SDL2/SDL.h>
#include <stdio.h>

class SpriteObject
{
public:
	SpriteObject();

	int id;
	char* fileName;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	int scale;
};
#endif