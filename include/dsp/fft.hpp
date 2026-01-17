/**
 * @file fft.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once
#include <array>
#include <complex>
#include <cmath>
#include "../core/frame.hpp"
#include "../core/spectre.hpp"
#include "../core/types.hpp"


namespace reson::dsp{

template<size_t N>

class FFT{

public:

    FFT() {
        compute_twiddle();
    }

    void process(const core::Frame<N>& in, core::Spectre<N>& out) const {

        for(size_t i = 0; i < N; i++){
            buffer[i] = { in[i], 0.0f };
        }
        
        bit_reverse(buffer);

        compute_fft(buffer);

        for(size_t i = 0; i < N; i ++){
            out[i] = buffer[i];
        }
    }

private:

    using Complex = core::ComplexSample;
    mutable std::array<Complex, N> buffer;
    std::array<Complex, N/2> twiddle;

    void compute_twiddle(){
        for(size_t i = 0; i < N / 2; i++){
            float angle = -2.0f * core::PI * i / N;
            twiddle[i] = { std::cos(angle), std::sin(angle) };
        }
    }

    void bit_reverse(std::array<Complex, N>& data) const {
        size_t j = 0;
        for (size_t i = 1; i < N; ++i) {
            size_t bit = N >> 1;
            while (j & bit) {
                j ^= bit;
                bit >>= 1;
            }
            j |= bit;
            if (i < j)
                std::swap(data[i], data[j]);
        }
    }

    void compute_fft(std::array<Complex, N>& data) const {
        for (size_t len = 2; len <= N; len <<= 1) {
            size_t half = len >> 1;
            size_t step = N / len;

            for (size_t i = 0; i < N; i += len) {
                for (size_t j = 0; j < half; ++j) {
                    const auto& w = twiddle[j * step];
                    Complex u = data[i + j];
                    Complex v = data[i + j + half] * w;

                    data[i + j] = u + v;
                    data[i + j + half] = u - v;
                }
            }
        }
    }

};


}

