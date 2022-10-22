#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "character.h"
#include "resources.h"

extern int g_width;
extern int g_height;

class Enemy : public Character {
   private:
    int animation_counter_ = 0;

   protected:
    void ChooseDirectionFromPosition();
    void MoveInDirection();
    void LoadDefaultFrame() override;
    void Animate() override;

   public:
    Enemy(Vector2f p_position, SDL_Texture* p_texture)
        : Character(p_position, Resources::Instance().get_enemy_texture()) {
        direction_ = Direction::Right;
    }
    void Update(SDL_Event* e) override;
};
