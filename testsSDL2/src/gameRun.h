#ifndef GAMERUN
#define GAMERUN

#include <SDL2/SDL.h>
#include "spriteObject.h"

class GameRun : public SpriteObject
{
public:
	
	GameRun();
	
	SpriteObject* background;
	SpriteObject* hero;
};
#endif