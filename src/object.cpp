#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"

void Object::LoadDefaultFrame() {
    current_frame_.x = 0;
    current_frame_.y = 0;
    // set frame width and height by it's texture size;
    SDL_QueryTexture(texture_, NULL, NULL, &current_frame_.w,
                     &current_frame_.h);
}

void Object::Init() {
    LoadDefaultFrame();
}

Object::~Object() {
    SDL_DestroyTexture(texture_);
}

float Object::getX() {
    return position_.x;
}

float Object::getY() {
    return position_.y;
}

void Object::setX(float p_x) {
    position_.x = p_x;
}

void Object::setY(float p_y) {
    position_.y = p_y;
}

int Object::getWidth() {
    return current_frame_.w;
}

int Object::getHeight() {
    return current_frame_.h;
}
