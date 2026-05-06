#pragma once
#include <cstddef>

namespace quark::memory {

struct Block {
    std::byte* data = nullptr;
    size_t capacity = 0;
    size_t offset = 0;
};

} // namespace quark::memory