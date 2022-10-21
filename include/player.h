#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <character.h>
#include <resources.h>
#include <iostream>

class Player : public Character {
   private:
    int animation_counter_ = 0;
    void MoveInDirection();
    void ChooseDirectionFromEvent(SDL_Event* e);

   protected:
    void LoadDefaultFrame() override;
    void Animate() override;

   public:
    Player(Vector2f p_position, SDL_Texture* p_texture)
        : Character(p_position, Resources::Instance().get_character_texture()) {
    }
    void Update(SDL_Event* e) override;
};
