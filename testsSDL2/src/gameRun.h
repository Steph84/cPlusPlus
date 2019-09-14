#ifndef GAMERUN
#define GAMERUN

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameRun
{
public:
	
	GameRun();
	SDL_Surface* LoadSurface(const char* &fileName);
	
	SDL_Surface* background;
	SDL_Surface* hero;
};
#endif