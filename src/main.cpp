#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

#include "entity.h"
#include "window.h"
#include "resources.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

void init_libraries() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
}

void init_ground(std::vector<std::shared_ptr<Entity>> *list, Resources* resources) {
    SDL_Texture* grassTexture = resources->getGrassTexture();
    int w, h;
    SDL_QueryTexture(grassTexture, NULL, NULL, &w, &h);
    
    int count = WINDOW_X / h;
    int low = WINDOW_Y - (2 * w);
    std::cout << "w: " << w  << " h: " << h << " count: " << count << " low: " << low << std::endl;
    
    for (int i = 0; i < count/3; i++) {
        list->push_back(std::make_shared<Entity>(Vector2f(i * h, low/4), resources->getGrassTexture()));
    }
}

int main(int argc, char *args[]) {
    Window window("GAME v1.0", WINDOW_X, WINDOW_Y);
    
    //todo: make singleton
    Resources* resources = new Resources(&window);

    std::vector<std::shared_ptr<Entity>> entities = {};
    init_ground(&entities, resources);

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