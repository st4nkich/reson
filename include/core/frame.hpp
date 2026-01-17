/**
 * @file frame.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */
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
