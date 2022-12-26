#include "enemy.h"

void Enemy::LoadDefaultFrame() {
    current_frame_.x = 0;
    current_frame_.y = 0;
    current_frame_.h = 32;
    current_frame_.w = 32;
}

void Enemy::ChooseDirectionFromPosition() {
    if (getX() == 0) {
        direction_ = Direction::Right;
    } else if (getX() == (g_width - getWidth())) {
        direction_ = Direction::Left;
    }
}

void Enemy::MoveInDirection() {
    if (direction_ == Direction::Left && getX() > 0) {
        setX(getX() - 1);
    } else if (direction_ == Direction::Right &&
               getX() < (g_width - getWidth())) {
        setX(getX() + 1);
    } else if (direction_ == Direction::Stale) {
    }
}

void Enemy::Animate() {
    if (current_frame_.y == 0)
        current_frame_.y = 32;
    else if (current_frame_.y == 32)
        current_frame_.y = 64;
    else
        current_frame_.y = 0;
}

void Enemy::Update(SDL_Event* e, int force = 10) {
    ChooseDirectionFromPosition();
    MoveInDirection();

    if (++animation_counter_ == 10) {
        Animate();
        animation_counter_ = 0;
    }
}
