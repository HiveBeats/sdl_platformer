#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "resources.h"
#include "window.h"

Resources::Resources(Window *p_window) {
    window = p_window;
    grassTexture = window->load_texture("res/gfx/ground_grass_1.png");
}

SDL_Texture * Resources::getGrassTexture() {
    return grassTexture;
}