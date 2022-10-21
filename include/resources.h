#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

class Resources {
   private:
    Window* window;
    SDL_Texture* grassTexture;
    SDL_Texture* characterTexture;

   public:
    Resources(Window* window);
    SDL_Texture* getGrassTexture();
    SDL_Texture* getCharacterTexture();
};
