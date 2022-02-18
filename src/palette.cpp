#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

//This is using the oil 6 palette from lospec, here's the link:
//https://lospec.com/palette-list/oil-6

static SDL_Color color1 = {0xFB, 0xF5, 0xEF};
static SDL_Color color2 = {0xF2, 0xD3, 0xAB};
static SDL_Color color3 = {0xC6, 0x9F, 0xA5};
static SDL_Color color4 = {0x8B, 0x6D, 0x9C};
static SDL_Color color5 = {0x49, 0x4D, 0x7E};
static SDL_Color color6 = {0x27, 0x27, 0x44};

SDL_Color color_array[] = {color1, color2, color3, color4, color5, color6};
