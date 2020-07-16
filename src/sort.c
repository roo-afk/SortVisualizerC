#include "sort.h"

#include "render.h"
#include <Windows.h>

void render_swap(SDL_Renderer *renderer, float *a, float *b, int i, int j) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw_swap(a, b, renderer, i,j);
	SDL_RenderPresent(renderer);
}


void swap(float *a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
	
	
}
/*Update the screen after a swap*/
void render_sort_function(SDL_Renderer * renderer, float * data, int n) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawLines(data, n, renderer);
	SDL_RenderPresent(renderer);
}
int partition(float v[], int low, int high, SDL_Renderer *renderer, int n) {
	
	float pivot = v[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if (v[j] < pivot)
		{
			i++;    // increment index of smaller element 
			swap(&v[i], &v[j]);
			render_swap(renderer, &v[i], &v[j], i, j);
			Sleep(DELAY / 2);
			render_sort_function(renderer, v, n);
			Sleep(DELAY);

			
		}
	}
	swap(&v[i + 1], &v[high]);
	render_swap(renderer, &v[i+1], &v[high], i+1, high);
	Sleep(DELAY / 2);
	render_sort_function(renderer, v, n);
	Sleep(DELAY);
	return (i + 1);
}
void quick_sort(float arr[], int low, int high, SDL_Renderer *renderer, int n) {
	
	if (low < high) {
		
		int newIndex = partition(arr, low, high, renderer, n);
		quick_sort(arr, low, newIndex - 1, renderer, n);
		quick_sort(arr, newIndex + 1, high, renderer, n);
	}
}
