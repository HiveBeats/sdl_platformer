#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"

Object::Object(Vector2f position, SDL_Texture* texture)
    : position_(position), texture_(texture) {
    LoadDefaultFrame();
}
/*
void Object::setDefaultFrame() {
    currentFrame.x = 0;
    currentFrame.y = 0;
    // set frame width and height by it's texture size;
    SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}
*/

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
