#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

#include "entity.h"
#include "window.h"
#include "resources.h"

void init_libraries() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
}

int main(int argc, char *args[]) {
    Window window("GAME v1.0", 1280, 720);
    
    //todo: make singleton
    Resources* resources = new Resources(&window);

    std::vector<std::shared_ptr<Entity>> entities = {
        std::make_shared<Entity>(Vector2f(0, 0), resources->getGrassTexture()),
        std::make_shared<Entity>(Vector2f(30, 0), resources->getGrassTexture()),
        std::make_shared<Entity>(Vector2f(30, 30), resources->getGrassTexture()),
        std::make_shared<Entity>(Vector2f(30, 60), resources->getGrassTexture()),
    };

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning) {
        // Get our controls and events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();

        for (auto &e : entities) {
            window.render(e.get());
        }

        window.display();
    }

    window.cleanup();
    SDL_Quit();

    return 0;
}