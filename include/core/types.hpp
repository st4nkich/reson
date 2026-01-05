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
 
