#include <stdio.h>
#include <stdlib.h>

#include "visualizer.h"
#include "sort.h"
#include "render.h"






int main(int argc, char **argv) {

	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Could not initialize sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window *window = SDL_CreateWindow("Sorting", 100, 100, (int) SCREEN_WIDTH, (int) SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Could not initialize window: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		printf("Error in renderer creation: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);


	renderData(renderer, values, N);

	SDL_RenderPresent(renderer);
	
	
	
	//SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return EXIT_SUCCESS;
}