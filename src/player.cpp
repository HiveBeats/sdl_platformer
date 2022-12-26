#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"

extern int g_width;
extern int g_height;

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

void Player::ChooseDirectionFromEvent(SDL_Event* e) {
    switch (e->type) {
        case SDL_KEYDOWN: {
            switch (e->key.keysym.sym) {
                case SDLK_LEFT:
                    direction_ = Direction::Left;
                    break;
                case SDLK_RIGHT:
                    direction_ = Direction::Right;
                    break;
                default:
                    direction_ = Direction::Stale;
                    break;
            }
            break;
        }
        case SDL_KEYUP: {
            direction_ = Direction::Stale;
            break;
        }
    }
}

void Player::MoveInDirection(int force) {
    int new_x = getX();
    if (direction_ == Direction::Left) {
        new_x -= force;
    } else if (direction_ == Direction::Right) {
        new_x += force;
    }

    // Check if the player is outside the screen boundaries
    if (new_x < 0 || new_x > (g_width - getWidth())) {
        // Change the direction to the opposite direction
        if (direction_ == Direction::Left) {
            direction_ = Direction::Right;
        } else {
            direction_ = Direction::Left;
        }
    } else {
        setX(new_x);
    }
}

void Player::Update(SDL_Event* e, int force) {
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    // Check for mouse click events
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        // Determine the direction based on the mouse position
        if (mouse_x < getX()) {
            direction_ = Direction::Left;
        } else if (mouse_x > getX() + getWidth()) {
            direction_ = Direction::Right;
        } else {
            direction_ = Direction::Stale;
        }
        // Set the player to not be in the stale state
        stale_ = false;
    } else if (e->type == SDL_MOUSEBUTTONUP) {
        // Set the player to be in the stale state
        stale_ = true;
    }

    // Decrease the force by a small amount each frame to simulate friction
    force = std::max(force - 1, 0);

    // Only move the player if it is not in the stale state or if the force is non-zero
    if (!stale_ || force > 0) {
        MoveInDirection(force);
    }

    if (++animation_counter_ == 10) {
        Animate();
        animation_counter_ = 0;
    }
}
