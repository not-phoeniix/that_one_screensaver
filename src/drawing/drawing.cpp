#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

extern SDL_Color color_array[];

void draw_bg(SDL_Renderer *renderer, int color) {
    SDL_SetRenderDrawColor(renderer, color_array[color].r, color_array[color].g, color_array[color].b, 0xFF);
    SDL_RenderClear(renderer);
}