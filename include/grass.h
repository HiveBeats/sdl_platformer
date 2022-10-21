#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "object.h"
#include "resources.h"

class Grass : public Object {
   public:
    Grass(Vector2f p_position, SDL_Texture* p_texture)
        : Object(p_position, Resources::Instance().get_grass_texture()) {}
};
