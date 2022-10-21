#pragma once
#include <memory>
#include <type_traits>
#include "object.h"

template <class T>
std::shared_ptr<T> CreateObject(Vector2f position, SDL_Texture* texture) {
    // Compile-time check
    static_assert(std::is_base_of<Object, T>::value,
                  "type parameter of this class must derive from Object");

    std::shared_ptr<T> pObject = std::make_shared<T>(position, texture);
    pObject->Init();

    return pObject;
}
