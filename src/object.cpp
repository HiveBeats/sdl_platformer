#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"

Object::Object(Vector2f p_position, SDL_Texture* p_texture)
    : position(p_position), texture(p_texture) {
    setDefaultFrame();
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
    SDL_DestroyTexture(texture);
}

Vector2f Object::getPosition() {
    return position;
}

float Object::getX() {
    return position.x;
}

float Object::getY() {
    return position.y;
}

void Object::setPosition(Vector2f p_position) {
    position = p_position;
}

void Object::setX(float p_x) {
    position.x = p_x;
}

void Object::setY(float p_y) {
    position.y = p_y;
}

int Object::getWidth() {
    return currentFrame.w;
}

int Object::getHeight() {
    return currentFrame.h;
}

SDL_Texture* Object::getTexture() {
    return texture;
}

SDL_Rect Object::getCurrentFrame() {
    return currentFrame;
}
