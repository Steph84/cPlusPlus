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
	Initialize* initialization = new Initialize();
	int initIndex = 0;
	initIndex = initialization -> InitializeSDL();
	if (initIndex < 0)
	{
		return -1;
	}

	initIndex = initialization -> CreateWindow();
	if (initIndex < 0)
	{
		return -1;
	}

	// create renderer (use VRAM)
	SDL_Renderer* renderer = SDL_CreateRenderer(initialization -> window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;	
	}

	GameRun* gameRun = new GameRun();




	// create surface
	// SDL_Surface* surface = IMG_Load("./data/background.png");
	// if(surface == nullptr)
	// {
	// 	SDL_Log("Could not create a surface: %s", SDL_GetError());
	// 	return -1;	
	// }

	// hero = IMG_Load("./data/heros.png");
	// if(hero == nullptr)
	// {
	// 	SDL_Log("Could not create a hero: %s", SDL_GetError());
	// 	return -1;	
	// }

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
	texture = SDL_CreateTextureFromSurface(renderer, gameRun -> background);
	if(texture == nullptr)
	{
		SDL_Log("Could not create a texture: %s", SDL_GetError());
		return -1;	
	}
	textureHero = SDL_CreateTextureFromSurface(renderer, gameRun -> hero);
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

		SDL_RenderClear(renderer);

		// draw the texture on the renderer
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderCopy(renderer, textureHero, &srcrect, &dstrect);

		SDL_RenderPresent(renderer);
		// break;
	}

	// destroy all the objects and close SDL

	// destroy the texture
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(textureHero);

	// destroy all the textures in the renderer then the renderer itself
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(initialization -> window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
