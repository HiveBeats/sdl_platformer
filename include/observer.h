#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

enum class Event {
    SUBJECT_MOVED,
    SUBJECT_WALL_COLLIDED,
    SUBJECT_HOLE_COLLIDED
};

class Object;  // Forward declare Object class

class Observer {
   protected:
    std::vector<Object*> observed_;

   public:
    Observer();
    virtual ~Observer() noexcept;
    virtual void OnNotify(const Object& entity, Event event) = 0;
    void RegisterSub(Object* s);
    void UnregisterSub(Object* s);
};
