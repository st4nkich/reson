/**
 * @file spectre.hpp
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
#include <complex>

namespace reson::core{

    template<size_t N>
    struct Spectre{
        std::array<std::complex<float>, N> bins;

        Spectre() = default;

        std::complex<float>& operator[](size_t i) { return bins[i]; }
        const std::complex<float>& operator[](size_t i) const { return bins[i]; }

        size_t length() const { return N; }
    };
}