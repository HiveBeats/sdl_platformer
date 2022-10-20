#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(Vector2f p_position, SDL_Texture *p_texture) : position(p_position), texture(p_texture) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    // set frame width and height by it's texture size;
    SDL_QueryTexture(p_texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

Vector2f Entity::getPosition() {
    return position;
}

float Entity::getX() {
    return position.x;
}

float Entity::getY() {
    return position.y;
}

void Entity::setPosition(Vector2f p_position) {
    position = p_position;
}

void Entity::setX(float p_x) {
    position.x = p_x;
}

void Entity::setY(float p_y) {
    position.y = p_y;
}

int Entity::getWidth() {
    return currentFrame.w;
}

int Entity::getHeight() {
    return currentFrame.h;
}

SDL_Texture *Entity::getTexture() {
    return texture;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}
