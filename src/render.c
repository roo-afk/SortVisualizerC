
#include "render.h"
#include "visualizer.h"
#include <stdlib.h>
#include "sort.h"

/*Get a random float value in a range*/
float float_rand(float min, float max) {
	float scale = rand() / (float)RAND_MAX; // ranges from 0.0 to 1.0
	return min + scale * (max - min);
}
// Given the float array values, of size n, generate random values ranging from 0 to N
void generateValues(float *data, int n) {
	for (int i = 0; i < n; i++) {
		data[i] = float_rand(0.0, (float) n);
	}
}


void drawLines(float *data, int nrLines, SDL_Renderer * renderer) {
	for (int i = 0; i < nrLines; ++i) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, i, (int) SCREEN_HEIGHT, i, (int) (SCREEN_HEIGHT - data[i]));

	}
}
void draw_swap(float *a, float *b, SDL_Renderer *renderer, int i, int j) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, i, (int)SCREEN_HEIGHT, i, (int)(SCREEN_HEIGHT - *a));
	SDL_RenderDrawLine(renderer, j, (int)SCREEN_HEIGHT, j, (int)(SCREEN_HEIGHT - *b));

}


void renderData(SDL_Renderer *renderer, float *data, int n) {
	generateValues(data, n);
	drawLines(data, n, renderer);
	// show shuffled data
	SDL_RenderPresent(renderer);
	//SDL_Delay(1000);
	//clear screen for updated data
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	quick_sort(data, 0, n - 1, renderer, n);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawLines(data, n, renderer);
}