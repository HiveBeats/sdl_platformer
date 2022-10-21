#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "direction.h"
#include "object.h"

class Character : public Object {
   public:
    Character(Vector2f p_position, SDL_Texture* p_texture)
        : Object(p_position, p_texture) {}
    virtual void Animate() {}
};
