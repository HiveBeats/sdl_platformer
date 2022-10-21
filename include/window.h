#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "object.h"

class Window {
   public:
    Window(const char* title, int w, int h);
    void QuerySize(int* w, int* h);
    SDL_Texture* LoadTexture(const char* filePath);
    void Cleanup();
    void Clear();
    void Render(Object* object);
    void Display();

   private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
};
