#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "initialize.h"

// Initialize/LoadContent/UnloadContent/Update/Draw
using namespace std;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 200;

int main(int argc, char *argv[])
{
	Initialize* initializer = new Initialize(); // ne fonctionne QUE comme ça !!!
	// Initialize initializer(); // ne fonctionne QUE comme ça !!!

	// initialize other objects
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr; // use RAM
	SDL_Renderer* renderer = nullptr; // use VRAM
	SDL_Texture* texture = nullptr;
	SDL_Surface* hero = nullptr; // use RAM
	SDL_Texture* textureHero = nullptr;

	initializer->InitializeWindow(window, WINDOW_WIDTH, WINDOW_HEIGHT);

	// create window
	// window = SDL_CreateWindow("SDL2 tests", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
	// 							WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	// if (window == nullptr)	
	// {
	// 	SDL_Log("Could not create a window: %s", SDL_GetError());
	// 	return -1;
	// }

	// create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;	
	}

	// create surface
	surface = IMG_Load("./data/background.png");
	if(surface == nullptr)
	{
		SDL_Log("Could not create a surface: %s", SDL_GetError());
		return -1;	
	}
	hero = IMG_Load("./data/heros.png");
	if(hero == nullptr)
	{
		SDL_Log("Could not create a hero: %s", SDL_GetError());
		return -1;	
	}

	// rectangles of source and destination
	SDL_Rect srcrect;
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = hero -> w;
	srcrect.h = hero -> h;

	SDL_Rect dstrect;
	dstrect.x = 10;
	dstrect.y = 10;
	dstrect.w = hero -> w * 2;
	dstrect.h = hero -> h * 2;


	// create texture
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(texture == nullptr)
	{
		SDL_Log("Could not create a texture: %s", SDL_GetError());
		return -1;	
	}
	textureHero = SDL_CreateTextureFromSurface(renderer, hero);
	if(textureHero == nullptr)
	{
		SDL_Log("Could not create a textureHero: %s", SDL_GetError());
		return -1;	
	}

	// free surface because don't need anymore
	SDL_FreeSurface(surface);
	SDL_FreeSurface(hero);


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
	}

	// destroy all the objects and close SDL

	// destroy the texture
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(textureHero);

	// destroy all the textures in the renderer then the renderer itself
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
