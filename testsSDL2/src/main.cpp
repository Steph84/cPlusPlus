#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameRun.h"
#include <tuple>
#include <vector>

// Initialize/LoadContent/UnloadContent/Update/Draw
using namespace std;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 200;

int main(int argc, char *argv[])
{
	// start = chrono::high_resolution_clock::now();
	// vector<int> vectorSurface;
	// for (int i = 0; i < 1000000; ++i)
	// {
	// 	vectorSurface.push_back(i*i);
	// }
	// end = chrono::high_resolution_clock::now();
	// elapsed = chrono::duration<double, milli>(end-start).count();
 //  	printf ("creation vector = %.f\n", elapsed);

	// start = chrono::high_resolution_clock::now();
	// for (int i = 0; i < vectorSurface.size(); ++i)
	// {
	// 	int b = vectorSurface.at(i);
	// }
	// end = chrono::high_resolution_clock::now();
	// elapsed = chrono::duration<double, milli>(end-start).count();
 //  	printf ("read vector = %.f\n", elapsed);

	// start = chrono::high_resolution_clock::now();
	// int d = vectorSurface.at(500000);
	// printf("%d\n", d);
	// end = chrono::high_resolution_clock::now();
	// elapsed = chrono::duration<double, milli>(end-start).count();
 //  	printf ("read vector = %.f\n", elapsed);


	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL\n");
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return -1;
	}

	// create window
	SDL_Window* window = SDL_CreateWindow("SDL2 tests", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)	
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}

	// create renderer (use VRAM)
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
