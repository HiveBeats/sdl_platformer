#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <algorithm>
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
    for (Observer* ob : observers_)
        ob->UnregisterSub(this);
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

void Object::AddObserver(Observer* observer) {
    if (observer != nullptr) {
        bool found = std::find(std::begin(observers_), std::end(observers_),
                               observer) != std::end(observers_);

        if (!found) {
            observers_.push_back(observer);
            observer->RegisterSub(this);
        }
    }
}

void Object::RemoveObserver(Observer* observer) {
    auto it = std::find(std::begin(observers_), std::end(observers_), observer);

    if (it != std::end(observers_)) {
        observers_.erase(it);
        observer->UnregisterSub(this);
    }
}

void Object::Notify(Event event) {
    for (Observer* ob : observers_)
        ob->OnNotify(*this, event);
}
