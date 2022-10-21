#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

#include "game-state.h"
#include "level-manager.h"
#include "window.h"

extern bool g_game_running;

class GameManager {
   private:
    Window* window_;
    GameState state_ = GameState::Game;
    std::shared_ptr<LevelManager> level_manager_;
    SDL_Event sdl_event_;
    void GetInput();
    void UpdateState();
    void Render();

   public:
    explicit GameManager(Window* window);
    ~GameManager();
    void Update();
};
