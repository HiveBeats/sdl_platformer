#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "direction.h"
#include "object.h"

class Character : public Object {
   protected:
    Direction direction_ = Direction::Stale;
    virtual void Animate() {}

   public:
    Character(Vector2f p_position, SDL_Texture* p_texture)
        : Object(p_position, p_texture) {}
    virtual void Update(SDL_Event* e, int force = 10) {}
};
