#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "direction.h"
#include "grass.h"
#include "object-factory.h"
#include "object.h"
#include "player.h"
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

void init_entities(std::vector<std::shared_ptr<Object>>* list) {
    Resources& resources = Resources::Instance();
    SDL_Texture* grass_texture = resources.get_grass_texture();
    int w, h;
    SDL_QueryTexture(grass_texture, NULL, NULL, &w, &h);

    int count = floor(static_cast<double>(g_width) / (w));
    int ground_offset = g_height - (h);

    for (int i = 0; i < count; i++) {
        Vector2f grass_position = Vector2f(i * w, ground_offset);
        auto grass_field = CreateObject<Grass>(grass_position, NULL);
        list->push_back(grass_field);
    }

    Vector2f player_position = Vector2f(2 * w, ground_offset - (h + (h / 4)));
    auto player = CreateObject<Player>(player_position, NULL);
    list->push_back(player);
}

int main(int argc, char* args[]) {
    init_libraries();
    Window window("GAME v1.0", WINDOW_X, WINDOW_Y);
    window.QuerySize(&g_width, &g_height);

    Resources::Create(&window);

    std::vector<std::shared_ptr<Object>> entities = {};
    init_entities(&entities);

    bool game_running = true;
    Direction direction = Direction::Stale;
    int count = 0;
    SDL_Event event;

    while (game_running) {
        Object* player = entities.back().get();

        // Get our controls and events
        // game_manager.update(event); //with it's internal state
        //   level_manager.update(event); //with it's internal state
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

        window.Clear();

        dynamic_cast<Player*>(player)->Update(&event);

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
