#include <iostream>
#include <array>
#include <algorithm>
#include "../include/core/frame.hpp"
#include "../include/core/types.hpp"
#include "../include/dsp/window.hpp"
#include "generator.hpp"

template<size_t N>
void sinus_test(float amplitude, float frequency, float sample_rate) {
    reson::core::Frame<N> before_window;
    before_window = create_single_sinusoid_frame<N>(amplitude, frequency, sample_rate);

    reson::dsp::Window<N> hann_window(reson::dsp::WindowType::Hann);
    reson::core::Frame<N> after_window = before_window;
    hann_window.apply_window(after_window);

    std::cout << "Before Window (first 10 samples):" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << before_window[i] << "\n";
    }
    std::cout << std::endl;

    std::cout << "After Hann Window (first 10 samples):" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << after_window[i] << "\n";
    }

    std::cout << "Before Window (last 10 samples):" << std::endl;
    for (size_t i = N - 10; i < N; ++i) {
        std::cout  << before_window[i] << "\n";
    }
    std::cout << std::endl;

    std::cout << "After Hann Window (last 10 samples):" << std::endl;
    for (size_t i = N - 10; i < N; ++i) {
        std::cout << after_window[i] << "\n";
    }
    std::cout << std::endl;
}

template<size_t N>
void coefficient_test() {
    reson::core::Frame<N> frame;

    for(size_t i = 0; i < N; ++i) {
        frame[i] = 1.0f;
    }

    reson::core::Frame<N> hanned_frame = frame;;
    reson::core::Frame<N> hamminged_frame = frame;

    reson::dsp::Window<N> hann_window(reson::dsp::WindowType::Hann);
    reson::dsp::Window<N> hamming_window(reson::dsp::WindowType::Hamming);

    hann_window.apply_window(hanned_frame);
    hamming_window.apply_window(hamminged_frame);

    std::cout << "Hann Window Coefficients (first 10):" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << hanned_frame[i] << "\n"; 
    }

    float max_hann = hanned_frame[0];
    float min_hann = hanned_frame[0];
    for (size_t i = 1; i < N; ++i) {
        if (hanned_frame[i] > max_hann) {
            max_hann = hanned_frame[i];
        }
        if (hanned_frame[i] < min_hann) {
            min_hann = hanned_frame[i];
        }
    }
    std::cout << "Max value in Hann window: " << max_hann << std::endl;
    std::cout << "Min value in Hann window: " << min_hann << std::endl; 

    std::cout << "Hamming Window Coefficients (first 10):" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << hamminged_frame[i] << "\n";
    }
    float max_hamming = hamminged_frame[0];
    float min_hamming = hamminged_frame[0];
    for (size_t i = 1; i < N; ++i) {
        if (hamminged_frame[i] > max_hamming) {
            max_hamming = hamminged_frame[i]; 
        }
        if (hamminged_frame[i] < min_hamming) {
            min_hamming = hamminged_frame[i];
        } 
    }
    std::cout << "Max value in Hamming window: " << max_hamming << std::endl;
    std::cout << "Min value in Hamming window: " << min_hamming << std::endl;

}

int main(){
    constexpr size_t N = 512;

    sinus_test<N>(1.0f, 440.0f, 16000.0f);
    coefficient_test<N>();

    return 0;
}