#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector2.h>

class Object {
   protected:
    Vector2f position_;
    SDL_Rect current_frame_;
    SDL_Texture* texture_;
    virtual void LoadDefaultFrame() {
        current_frame_.x = 0;
        current_frame_.y = 0;
        // set frame width and height by it's texture size;
        SDL_QueryTexture(texture_, NULL, NULL, &current_frame_.w,
                         &current_frame_.h);
    }

   public:
    Object(Vector2f position, SDL_Texture* texture);
    ~Object();

    Vector2f get_position() const { return position_; }
    void set_position(Vector2f position) {position_ = position; }
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);

    int getWidth();
    int getHeight();

    SDL_Texture* get_texture() const { return texture_; }
    void set_texture(SDL_Texture* texture) { texture_ = texture; }

    SDL_Rect get_current_frame() const { return current_frame_; }
};
