
#ifndef RENDER_H_
#define RENDER_H_
#include <SDL.h>

#define DELAY 5
void drawLines(float *data, int nrLines, SDL_Renderer * renderer);
void draw_swap(float *a, float *b, SDL_Renderer *renderer, int i, int j);
void renderData(SDL_Renderer *renderer, float *data, int n);
#endif // RENDER_H_




