#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

#include "entity.h"
#include "player.h"
#include "window.h"
#include "resources.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

int w_width, w_height;

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
    
    int count = w_width / w;
    int low = w_height - (2 * h);
    
    for (int i = 0; i < count/3; i++) {
        list->push_back(std::make_shared<Entity>(Vector2f(i * h, low/4), resources->getGrassTexture()));
    }
    list->push_back(std::make_shared<Player>(Vector2f((count/3/2) * h, low/6 + 10), resources->getCharacterTexture()));
}

int main(int argc, char *args[]) {
    Window window("GAME v1.0", WINDOW_X, WINDOW_Y);
    window.query_size(&w_width, &w_height);

    //todo: make singleton
    Resources* resources = new Resources(&window);

    std::vector<std::shared_ptr<Entity>> entities = {};
    init_ground(&entities, resources);

    bool gameRunning = true;
    bool left = true;
    int count = 0;
    SDL_Event event;

    while (gameRunning) {
        // Get our controls and events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();

        Entity* player = entities.back().get();
        if (left && player->getX() > 0) {
            player->setX(player->getX() - 1);
        }
        else if (player->getX() == 0) {
            left = false;
            player->setX(player->getX() + 1);
        }
        else if (!left && player->getX() < 192) {
            player->setX(player->getX() + 1);
        }
        else if (player->getX() == 192) {
            left = true;
            player->setX(player->getX() - 1);
        }

        if (++count == 10) {
            dynamic_cast<Player*>(player)->animate();
            count = 0;
        }


        for (auto &e : entities) {
            window.render(e.get());
        }

        window.display();
        SDL_Delay(16);
    }

    window.cleanup();
    SDL_Quit();

    return 0;
}