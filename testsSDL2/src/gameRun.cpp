#include "gameRun.h"

GameRun::GameRun()
{
	string fileName = "background.png";
	background = SpriteObjectCreation(fileName, 1);
	fileName = "heros.png";
	hero = SpriteObjectCreation(fileName, 2);
	fileName.clear();
}