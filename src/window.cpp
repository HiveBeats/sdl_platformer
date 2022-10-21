#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "entity.h"
#include "window.h"

void fill_rect(SDL_Rect *rect, int x, int y, int h, int w) {
    rect->x = x;
    rect->y = y;
    rect->h = h;
    rect->w = w;
}

Window::Window(const char *p_title, int p_w, int p_h)
    : window(NULL), renderer(NULL) {
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *Window::load_texture(const char *p_filePath) {
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void Window::query_size(int* w, int*h) {
    SDL_GetRendererOutputSize(renderer, w, h);
}

void Window::cleanup() {
    SDL_DestroyWindow(window);
}

void Window::clear() {
    SDL_RenderClear(renderer);
}

void Window::render(Entity *p_entity) {
    SDL_Rect currentFrame = p_entity->getCurrentFrame();

    SDL_Rect src;
    fill_rect(&src, currentFrame.x, currentFrame.y, currentFrame.h, currentFrame.w);

    SDL_Rect dst;
    fill_rect(&dst, p_entity->getX() * 4, p_entity->getY() * 4, currentFrame.h * 4, currentFrame.w * 4);

    SDL_RenderCopy(renderer, p_entity->getTexture(), &src, &dst);
}

void Window::display() {
    SDL_RenderPresent(renderer);
}