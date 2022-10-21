#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <character.h>
#include <resources.h>
#include <iostream>

class Player : public Character {
   protected:
    void LoadDefaultFrame() override;

   public:
    Player(Vector2f p_position, SDL_Texture* p_texture)
        : Character(p_position, Resources::Instance().get_character_texture()) {
    }
    void Animate() override;
};
