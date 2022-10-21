#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <object.h>
#include <iostream>

class Player : public Object {
   protected:
    void LoadDefaultFrame() override {
        std::cout << "player frame setter called" << position_.x << std::endl;
        current_frame_.x = 0;
        current_frame_.y = 0;
        current_frame_.h = 64;
        current_frame_.w = 64;
    }

   public:
    Player(Vector2f p_position, SDL_Texture* p_texture)
        : Object(p_position, p_texture) {
        // why not called from base?
        LoadDefaultFrame();
    }
    void Animate();
};
