#include "player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Player::animate() {
    if (currentFrame.y == 0)
        currentFrame.y = 64;
    else currentFrame.y = 0;
}