#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"

void Player::Animate() {
    if (current_frame_.y == 0)
        current_frame_.y = 64;
    else
        current_frame_.y = 0;
}

void Player::LoadDefaultFrame() {
    current_frame_.x = 0;
    current_frame_.y = 0;
    current_frame_.h = 64;
    current_frame_.w = 64;
}
