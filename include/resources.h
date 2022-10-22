#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

class Resources {
   private:
    Window* window_;
    SDL_Texture* grass_texture_;
    SDL_Texture* character_texture_;
    SDL_Texture* enemy_texture_;
    Resources() {}

   public:
    static Resources& Create(Window* window) {
        static Resources INSTANCE;
        if (window != NULL) {
            INSTANCE.window_ = window;
            INSTANCE.grass_texture_ =
                window->LoadTexture("res/gfx/ground_grass_1.png");
            INSTANCE.character_texture_ =
                window->LoadTexture("res/gfx/hulking_knight.png");
            INSTANCE.enemy_texture_ =
                window->LoadTexture("res/gfx/AnimationSheet_Character.png");
        }

        return INSTANCE;
    }
    static Resources& Instance() { return Create(NULL); }
    Resources(Resources const&) = delete;
    void operator=(Resources const&) = delete;

    SDL_Texture* get_grass_texture() const { return grass_texture_; }
    SDL_Texture* get_character_texture() const { return character_texture_; }
    SDL_Texture* get_enemy_texture() const { return enemy_texture_; }
};
