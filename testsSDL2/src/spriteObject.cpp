#include "spriteObject.h"

SpriteObject::SpriteObject()
{
	id = -1;
	// fileName = "";
	surface = nullptr;
	texture = nullptr;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	destRect.x = 0;
	destRect.y = 0;
	destRect.w = 32;
	destRect.h = 32;
	scale = 1;
}

SpriteObject* SpriteObject::SpriteObjectCreation(string &pFileName, int pScale)
{
	SpriteObject* result;
	result -> fileName = pFileName;
	result -> scale = pScale;
	result -> surface = IMG_Load((pathData + pFileName).c_str());

	result -> srcRect.x = 0;
	result -> srcRect.y = 0;
	result -> srcRect.w = surface -> w;
	result -> srcRect.h = surface -> h;
	result -> destRect.x = 0;
	result -> destRect.y = 0;
	result -> destRect.w = surface -> w * pScale;
	result -> destRect.h = surface -> h * pScale;

	return result;
}