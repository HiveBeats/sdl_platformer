#pragma once
#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Resources {
private:
    Window* window;
    SDL_Texture *grassTexture;

public:
    Resources(Window *window);
    SDL_Texture *getGrassTexture();
};
