#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "object.h"
#include "window.h"

void fill_rect(SDL_Rect* rect, int x, int y, int h, int w) {
    rect->x = x;
    rect->y = y;
    rect->h = h;
    rect->w = w;
}

Window::Window(const char* title, int w, int h)
    : window_(NULL), renderer_(NULL) {
    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if (window_ == NULL) {
        std::cout << "Window failed to init. Error: " << SDL_GetError()
                  << std::endl;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Window::LoadTexture(const char* filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer_, filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError()
                  << std::endl;

    return texture;
}

void Window::QuerySize(int* w, int* h) {
    SDL_GetWindowSize(window_, w, h);
}

void Window::Cleanup() {
    SDL_DestroyWindow(window_);
}

void Window::Clear() {
    SDL_RenderClear(renderer_);
}

void Window::Render(Object* object) {
    SDL_Rect current_frame = object->get_current_frame();

    SDL_Rect src;
    fill_rect(&src, current_frame.x, current_frame.y, current_frame.h,
              current_frame.w);

    SDL_Rect dst;
    fill_rect(&dst, object->getX() * 4, object->getY() * 4, current_frame.h * 4,
              current_frame.w * 4);

    SDL_RenderCopy(renderer_, object->get_texture(), &src, &dst);
}

void Window::Display() {
    SDL_RenderPresent(renderer_);
}
