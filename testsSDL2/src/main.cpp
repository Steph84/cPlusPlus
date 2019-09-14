#include <stdio.h>
#include <iostream>
#include "gameRun.h"
#include "initialize.h"
#include <tuple>
#include <vector>

// Initialize/LoadContent/UnloadContent/Update/Draw
using namespace std;

int main(int argc, char *argv[])
{
	// Initialization of the program : SDL, window and renderer
	Initialize* initialization = new Initialize();
	int initIndex = 0;
	initIndex = initialization -> InitializeSDL();
	if (initIndex < 0) { return -1; }
	initIndex = initialization -> CreateWindow();
	if (initIndex < 0) { return -1; }
	initIndex = initialization -> CreateRenderer();
	if (initIndex < 0) { return -1; }


	// creation of the game
	GameRun* gameRun = new GameRun();


	SDL_Texture* texture = nullptr;
	SDL_Texture* textureHero = nullptr;

	// rectangles of source and destination
	SDL_Rect srcrect;
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = gameRun -> hero -> w;
	srcrect.h = gameRun -> hero -> h;
	
	SDL_Rect dstrect;
	dstrect.x = 10;
	dstrect.y = 10;
	dstrect.w = gameRun -> hero -> w * 2;
	dstrect.h = gameRun -> hero -> h * 2;


	// create texture
	texture = SDL_CreateTextureFromSurface(initialization -> renderer, gameRun -> background);
	if(texture == nullptr)
	{
		SDL_Log("Could not create a texture: %s", SDL_GetError());
		return -1;	
	}
	textureHero = SDL_CreateTextureFromSurface(initialization -> renderer, gameRun -> hero);
	if(textureHero == nullptr)
	{
		SDL_Log("Could not create a textureHero: %s", SDL_GetError());
		return -1;	
	}

	// free surface because don't need anymore
	SDL_FreeSurface(gameRun -> background);
	SDL_FreeSurface(gameRun -> hero);


	// game loop
	while (true)
	{
		// manage the close of the window
		SDL_Event event;
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				break;
			}
		}

		SDL_RenderClear(initialization -> renderer);

		// draw the texture on the renderer
		SDL_RenderCopy(initialization -> renderer, texture, NULL, NULL);
		SDL_RenderCopy(initialization -> renderer, textureHero, &srcrect, &dstrect);

		SDL_RenderPresent(initialization -> renderer);
		// break;
	}

	// destroy all the objects and close SDL

	// destroy the texture
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(textureHero);

	// destroy all the textures in the renderer then the renderer itself
	SDL_DestroyRenderer(initialization -> renderer);
	SDL_DestroyWindow(initialization -> window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
