#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "resources.h"
#include "window.h"

Resources::Resources(Window* window) {
    window_ = window;
    grass_texture_ = window_->LoadTexture("res/gfx/ground_grass_1.png");
    character_texture_ = window_->LoadTexture("res/gfx/hulking_knight.png");
}
