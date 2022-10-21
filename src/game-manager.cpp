#include "game-manager.h"

GameManager::GameManager(Window* window) {
    window_ = window;
    level_manager_ = std::make_shared<LevelManager>();
}

GameManager::~GameManager() {}

void GameManager::GetInput() {
    // todo: while (SDL_PollEvent) to apply all events from the event queue
    // and then transform into array of actions to be applied
    SDL_PollEvent(&sdl_event_);
    switch (sdl_event_.type) {
        case SDL_QUIT: {
            g_game_running = false;
            break;
        }
        case SDL_KEYDOWN: {
            switch (sdl_event_.key.keysym.sym) {
                case SDLK_ESCAPE:
                    g_game_running = false;
                    break;
            }
            break;
        }
    }
}

void GameManager::UpdateState() {
    if (state_ == GameState::Game) {
        level_manager_->Update(&sdl_event_);
    }
}

void GameManager::Render() {
    window_->Clear();

    if (state_ == GameState::Game) {
        for (auto& obj : level_manager_->get_objects()) {
            window_->Render(obj.get());
        }
    }

    window_->Display();
    SDL_Delay(16);
}

void GameManager::Update() {
    GetInput();
    UpdateState();
    Render();
}
