#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "level-manager.h"
#include "resources.h"
#include "window.h"

#define WINDOW_X 640
#define WINDOW_Y 480

int g_width, g_height;

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
    LevelManager* level_manager = new LevelManager();

    bool game_running = true;
    SDL_Event event;

    while (game_running) {
        // Get our controls and events
        // game_manager.update(event); //with it's internal state
        //   level_manager.update(event); //with it's internal state

        // todo: while (SDL_PollEvent) to apply all events from the event queue
        // and then transform into array of actions to be applied
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT: {
                game_running = false;
                break;
            }
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        game_running = false;
                        break;
                }
                break;
            }
        }
        level_manager->Update(&event);

        window.Clear();

        for (auto& obj : level_manager->get_objects()) {
            window.Render(obj.get());
        }

        window.Display();
        SDL_Delay(16);
    }

    delete level_manager;

    window.Cleanup();
    SDL_Quit();

    return 0;
}
