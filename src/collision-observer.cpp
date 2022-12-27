#include <typeinfo>
#include "collision-observer.h"
#include "enemy.h"
#include "object.h"

CollisionObserver::CollisionObserver() {}

void CollisionObserver::OnNotify(const Object& entity, Event event) {
    if (event == Event::SUBJECT_MOVED) {
        checkCollisions(const_cast<Object*>(&entity));
    }
}

bool CollisionObserver::collided(Object* a, Object* b) {
    int left_a = a->getX();
    int right_a = a->getX() + a->getWidth();
    int top_a = a->getY();
    int bottom_a = a->getY() + a->getHeight();

    int left_b = b->getX();
    int right_b = b->getX() + b->getWidth();
    int top_b = b->getY();
    int bottom_b = b->getY() + b->getHeight();

    if (left_a > right_b || left_b > right_a) {
        return false;
    }

    if (top_a > bottom_b || top_b > bottom_a) {
        return false;
    }

    return true;
}

void CollisionObserver::checkCollisions(Object* b) {
    for (auto& o : observed_) {
        if (collided(b, o)) {
            if (typeid(o) == typeid(Enemy)) {  // todo: holes
                b->Notify(Event::SUBJECT_HOLE_COLLIDED);
            } else {
                b->Notify(Event::SUBJECT_WALL_COLLIDED);
            }
        }
    }
}
