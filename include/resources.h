#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

class Resources {
   private:
    Window* window_;
    SDL_Texture* grass_texture_;
    SDL_Texture* character_texture_;

   public:
    explicit Resources(Window* window);
    SDL_Texture* getGrassTexture() const { return grass_texture_; }
    SDL_Texture* getCharacterTexture() const { return character_texture_; }
};
