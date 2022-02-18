#include <iostream>
#include <SDL2/SDL.h>
#include "timer/timer.h"
#include "drawing/drawing.h"
#include "player/player.h"

using namespace std;

const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
const int SCREEN_FPS_LIMIT = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS_LIMIT;

SDL_Window *main_window = NULL;
SDL_Renderer *main_renderer = NULL;

void init() {
    SDL_Init(SDL_INIT_VIDEO);

    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    main_window = SDL_CreateWindow("moving from arrow keys (or wasd) test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void end() {
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);

    SDL_Quit();
}

int main(int argc, char *args[]) {
    init();

    bool running = true;
    SDL_Event e;
    custom_timer cap_timer;
    player_class player;

    player.PLAYER_WIDTH = 100;
    player.PLAYER_VELOCITY = 5;

    while(running) {
        cap_timer.start();

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                running = false;
            } else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        draw_bg(main_renderer, 5);
        
        player.move(SCREEN_HEIGHT, SCREEN_WIDTH);
        player.render(main_renderer, 0, 5, 5, 15);

        SDL_RenderPresent(main_renderer);

        int frame_ticks = cap_timer.get_ticks();
        if(frame_ticks < SCREEN_TICKS_PER_FRAME) {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frame_ticks);
        }
    }

    end();

    return 0;
}