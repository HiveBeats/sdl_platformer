#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <object.h>
#include <iostream>

class Player : public Object {
   protected:
    void setDefaultFrame() override {
        std::cout << "player frame setter called" << position.x << std::endl;
        currentFrame.x = 0;
        currentFrame.y = 0;
        currentFrame.h = 64;
        currentFrame.w = 64;
    }

   public:
    Player(Vector2f p_position, SDL_Texture* p_texture)
        : Object(p_position, p_texture) {
        //why not called from base?
        setDefaultFrame();
    }
    void animate();
};