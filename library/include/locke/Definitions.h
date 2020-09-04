#pragma once
#include <cstdint>

namespace locke {
    template<typename t>
    size_t arraySize(t arr[]) {
        return sizeof(arr) / sizeof(arr[0]);
    }
}