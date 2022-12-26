#include <algorithm>
#include "object.h"
#include "observer.h"

Observer::Observer() : observed_{} {}

Observer::~Observer() noexcept {
    for (Object* sub : observed_)
        sub->removeObserver(this);
}

void Observer::registerSub(Object* s) {
    bool found = std::find(std::begin(observed_), std::end(observed_), s) !=
                 std::end(observed_);

    if (!found) {
        observed_.push_back(s);
    }
}

void Observer::unregisterSub(Object* s) {
    auto it = std::find(std::begin(observed_), std::end(observed_), s);

    if (it != std::end(observed_)) {
        observed_.erase(it);
    }
}
