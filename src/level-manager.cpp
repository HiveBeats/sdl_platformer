#include "grass.h"
#include "level-manager.h"
#include "object-factory.h"

LevelManager::LevelManager() {
    objects_ = new std::vector<std::shared_ptr<Object>>();

    Resources& resources = Resources::Instance();
    SDL_Texture* grass_texture = resources.get_grass_texture();
    int w, h;
    SDL_QueryTexture(grass_texture, NULL, NULL, &w, &h);

    int count = floor(static_cast<double>(g_width) / (w));
    int ground_offset = g_height - (h);

    for (int i = 0; i < count; i++) {
        Vector2f grass_position = Vector2f(i * w, ground_offset);
        auto grass_field = CreateObject<Grass>(grass_position, NULL);
        objects_->push_back(grass_field);
    }

    Vector2f player_position = Vector2f(2 * w, ground_offset - (h + (h / 4)));
    player_ = CreateObject<Player>(player_position, NULL);
    objects_->push_back(player_);
}

LevelManager::~LevelManager() {
    delete objects_;
}

void LevelManager::Update(SDL_Event* e) {
    player_.get()->Update(e);
}
