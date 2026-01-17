#pragma once
#include <cstddef>
#include <array>
#include "types.hpp"

namespace reson::core{

    template<size_t N>
    struct Frame{
        std::array<float, N> samples;
        
        float& operator[](size_t i) { return samples[i]; }
        const float& operator[](size_t i) const { return samples[i]; }
        
        size_t length() const { return N; }
    };

}
