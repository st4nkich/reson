/**
 * @file types.hpp
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
#include <complex>

namespace reson::core{
    using Sample = float;
    using ComplexSample = std::complex<float>;
    constexpr size_t DEFAULT_FRAME_SIZE = 1024;
    constexpr float DEFAULT_SAMPLE_RATE = 44100.0f; 
    constexpr float PI = 3.14159265359f;



}
 
