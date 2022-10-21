#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <memory>
#include <vector>

#include "object.h"
#include "player.h"

extern int g_width;
extern int g_height;

class LevelManager {
   private:
    std::shared_ptr<Player> player_;
    std::vector<std::shared_ptr<Object>>* objects_;

   public:
    LevelManager();
    ~LevelManager();
    std::vector<std::shared_ptr<Object>> const& get_objects() const {
        return (*objects_);
    }
    void Update(SDL_Event* e);
};
