#include <iostream>
#include <SDL2/SDL.h>
#include "player.h"

using namespace std;

extern SDL_Color color_array[];

player_class::player_class() {
    pos_x = 0;
    pos_y = 0;

    vel_x = 3;
    vel_y = 3;
}

void player_class::move(int screen_height, int screen_width) {
    pos_x += vel_x;

    if( (pos_x < 0) || (pos_x + PLAYER_WIDTH > screen_width)) {
        vel_x = -vel_x;
    }

    pos_y += vel_y;

    if( (pos_y < 0) || (pos_y + PLAYER_WIDTH > screen_height)) {
        vel_y = -vel_y;
    }
}

void player_class::render(SDL_Renderer *renderer, int color1, int color2, int inner_size, int inner_size2) {
    SDL_Rect rect1 = {
        .x = pos_x,
        .y = pos_y,
        .w = PLAYER_WIDTH,
        .h = PLAYER_WIDTH
    };

    SDL_Rect rect2 = {
        .x = pos_x + inner_size,
        .y = pos_y + inner_size,
        .w = PLAYER_WIDTH - 2 * inner_size,
        .h = PLAYER_WIDTH - 2 * inner_size 
    };

    SDL_Rect rect3 = {
        .x = pos_x + inner_size2,
        .y = pos_y + inner_size2,
        .w = PLAYER_WIDTH - 2 * inner_size2,
        .h = PLAYER_WIDTH - 2 * inner_size2 
    };

    SDL_SetRenderDrawColor(renderer, color_array[color1].r, color_array[color1].g, color_array[color1].b, 0xFF);
    SDL_RenderFillRect(renderer, &rect1);

    SDL_SetRenderDrawColor(renderer, color_array[color2].r, color_array[color2].g, color_array[color2].b, 0xFF);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_SetRenderDrawColor(renderer, color_array[color1].r, color_array[color1].g, color_array[color1].b, 0xFF);
    SDL_RenderFillRect(renderer, &rect3);
}