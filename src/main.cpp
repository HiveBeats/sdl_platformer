#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

#include "object-factory.h"
#include "object.h"
#include "player.h"
#include "resources.h"
#include "window.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

int w_width, w_height;

void init_libraries() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError()
                  << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError()
                  << std::endl;
}

void init_entities(std::vector<std::shared_ptr<Object>>* list) {
    Resources& resources = Resources::Instance();
    SDL_Texture* grassTexture = resources.get_grass_texture();
    int w, h;
    SDL_QueryTexture(grassTexture, NULL, NULL, &w, &h);

    int count = w_width / w;
    int low = w_height - (2 * h);

    for (int i = 0; i < count / 3; i++) {
        auto grass_field = CreateObject<Object>(Vector2f(i * h, low / 4),
                                                resources.get_grass_texture());
        list->push_back(grass_field);
    }

    auto player =
        CreateObject<Player>(Vector2f((count / 3 / 2) * h, low / 6 + 10),
                             resources.get_character_texture());
    list->push_back(player);
}

int main(int argc, char* args[]) {
    init_libraries();
    Window window("GAME v1.0", WINDOW_X, WINDOW_Y);
    window.QuerySize(&w_width, &w_height);

    Resources& resources = Resources::Create(&window);

    std::vector<std::shared_ptr<Object>> entities = {};
    init_entities(&entities);

    bool gameRunning = true;
    bool left = true;
    int count = 0;
    SDL_Event event;

    while (gameRunning) {
        // Get our controls and events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    gameRunning = false;
                    break;
                }
            }
        }

        window.Clear();

        Object* player = entities.back().get();
        if (left && player->getX() > 0) {
            player->setX(player->getX() - 1);
        } else if (player->getX() == 0) {
            left = false;
            player->setX(player->getX() + 1);
        } else if (!left && player->getX() < 192) {
            player->setX(player->getX() + 1);
        } else if (player->getX() == 192) {
            left = true;
            player->setX(player->getX() - 1);
        }

        if (++count == 10) {
            dynamic_cast<Player*>(player)->Animate();
            count = 0;
        }

        for (auto& e : entities) {
            window.Render(e.get());
        }

        window.Display();
        SDL_Delay(16);
    }

    window.Cleanup();
    SDL_Quit();

    return 0;
}
