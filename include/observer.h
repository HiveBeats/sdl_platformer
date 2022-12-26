#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "object.h"

enum class Event {
    SUBJECT_MOVED,
    SUBJECT_WALL_COLLIDED,
    SUBJECT_HOLE_COLLIDED
};

class Object;

class Observer {
   protected:
    std::vector<Object*> observed_;

   public:
    Observer();
    virtual ~Observer() noexcept;
    virtual void onNotify(const Object& entity, Event event) = 0;
    void registerSub(Object* s);
    void unregisterSub(Object* s);
};
