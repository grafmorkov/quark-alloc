#pragma once

#include <utility>
#include "arena.h"

namespace quark::memory {

// create object
template<typename T, typename... Args>
T* make(Arena& arena, Args&&... args) {
    void* mem = arena.alloc(sizeof(T), alignof(T));
    return new (mem) T(std::forward<Args>(args)...);
}

// array allocation
template<typename T>
T* alloc_array(Arena& arena, size_t count) {
    void* mem = arena.alloc(sizeof(T) * count, alignof(T));
    return reinterpret_cast<T*>(mem);
}

// raw object
template<typename T>
T* alloc_object(Arena& arena) {
    return reinterpret_cast<T*>(arena.alloc(sizeof(T), alignof(T)));
}

} // namespace quark::memory