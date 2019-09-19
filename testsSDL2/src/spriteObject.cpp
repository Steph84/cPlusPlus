#include "spriteObject.h"

SpriteObject::SpriteObject()
{
	id -1;
	fileName = "";
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