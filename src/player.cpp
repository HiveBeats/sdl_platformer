#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"

void Player::Animate() {
    if (current_frame_.y == 0)
        current_frame_.y = 64;
    else
        current_frame_.y = 0;
}
