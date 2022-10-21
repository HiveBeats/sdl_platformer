#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "object.h"

class Window {
   public:
    Window(const char* p_title, int p_w, int p_h);
    void query_size(int* w, int* h);
    SDL_Texture* load_texture(const char* p_filePath);
    void cleanup();
    void clear();
    void render(Object* p_object);
    void display();

   private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};