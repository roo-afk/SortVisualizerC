#ifndef SORT_H_
#define SORT_H_
#include <SDL.h>

/*Swap two float values. This function may also be used by algorithms like bubble sort
  @param a first value 
  @param b second value */
void swap(float *a, float *b);

/*Partition function used by quickSort*/
int partition(float v[], int low, int high, SDL_Renderer *renderer, int n);

void quick_sort(float arr[], int low, int high, SDL_Renderer *renderer, int n);

void render_sort_function(SDL_Renderer *renderer, float *data, int n);



#endif // SORT_H_

