#pragma once
#include <cstddef>

namespace quark::memory {

struct Stats {
    size_t used = 0;
    size_t peak = 0;
    size_t allocations = 0;
    size_t blocks = 0;
};

} // namespace quark::memory