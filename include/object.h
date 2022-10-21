#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector2.h>

class Object {
   protected:
    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    virtual void setDefaultFrame() {
        currentFrame.x = 0;
        currentFrame.y = 0;
        // set frame width and height by it's texture size;
        SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
    };

   public:
    Object(Vector2f p_position, SDL_Texture* p_texture);
    ~Object();

    Vector2f getPosition();
    float getX();
    float getY();
    void setPosition(Vector2f p_position);
    void setX(float p_x);
    void setY(float p_y);

    int getWidth();
    int getHeight();

    SDL_Texture* getTexture();
    void setTexture(SDL_Texture* p_texture);

    SDL_Rect getCurrentFrame();
};