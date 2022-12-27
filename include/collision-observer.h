#pragma once
#include "observer.h"

class Object;
class Player;

class CollisionObserver : public Observer {
   public:
    CollisionObserver();

    void OnNotify(const Object& entity, Event event) override;

    int get_first_hit() const noexcept { return first_hit; }
    void reset_first_hit() noexcept { first_hit = -1; }

   private:
    int first_hit = -1;

    bool collided(Object* b, Object* b2);
    void checkCollisions(Object* b);
};
