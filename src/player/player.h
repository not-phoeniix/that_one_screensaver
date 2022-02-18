#pragma once

class player_class {
    public:
        player_class();

        int PLAYER_WIDTH;
        int PLAYER_VELOCITY;
        
        void move(int screen_height, int screen_width);
        void render(SDL_Renderer *renderer, int color1, int color2, int inner_size, int inner_size2);
    private:
        int pos_x, pos_y;
        int vel_x, vel_y;
};