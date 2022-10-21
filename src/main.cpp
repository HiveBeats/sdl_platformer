#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "game-manager.h"
#include "resources.h"
#include "window.h"

#define WINDOW_X 640
#define WINDOW_Y 480

int g_width, g_height;
bool g_game_running;

void init_libraries() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError()
                  << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError()
                  << std::endl;
}

int main(int argc, char* args[]) {
    init_libraries();
    Window window("GAME v1.0", WINDOW_X, WINDOW_Y);
    window.QuerySize(&g_width, &g_height);

    Resources::Create(&window);
    GameManager* game_manager = new GameManager(&window);

    g_game_running = true;

    while (g_game_running) {
        game_manager->Update();
    }

    delete game_manager;

    window.Cleanup();
    SDL_Quit();

    return 0;
}
