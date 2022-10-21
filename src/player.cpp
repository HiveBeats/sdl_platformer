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

void Player::MoveInDirection() {
    if (direction_ == Direction::Left && getX() > 0) {
        setX(getX() - 1);
    } else if (direction_ == Direction::Right &&
               getX() < (g_width - getWidth())) {
        setX(getX() + 1);
    } else if (direction_ == Direction::Stale) {
    }
}

// todo: replace SDL_event with anything custom like PLAYER_ACTION or whatever
void Player::Update(SDL_Event* e) {
    ChooseDirectionFromEvent(e);
    MoveInDirection();

    if (++animation_counter_ == 10) {
        Animate();
        animation_counter_ = 0;
    }
}
