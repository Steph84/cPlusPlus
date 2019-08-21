#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define DATA_PATH "../"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

int main(int argc, char *argv[])
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL\n");
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return -1;
	}

	// initialize other objects
	SDL_Window* window = nullptr;
	// SDL_Surface* surface = nullptr; // use RAM
	SDL_Renderer* renderer = nullptr; // use VRAM
	SDL_Texture* bg = nullptr;
	int w, h; // texture width & height

	// create window
	window = SDL_CreateWindow("SDL2 tests", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr)	
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}

	// create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;	
	}

	// create background
	bg = IMG_LoadTexture(renderer, ("%sbackground.png", DATA_PATH));
	SDL_QueryTexture(bg, NULL, NULL, &w, &h);
	SDL_Rect texr; texr.x = WINDOW_WIDTH/2; texr.y = WINDOW_HEIGHT/2; texr.w = w*2; texr.h = h*2;

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

		// SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg, NULL, &texr);
		SDL_RenderPresent(renderer);
	}

	// destroy all the objects and close SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
