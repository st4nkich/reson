#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include "../include/core/frame.hpp"
#include "../include/core/types.hpp"
#include "../include/dsp/fft.hpp"
#include "generator.hpp"
#include "../include/core/spectre.hpp"
#include "../include/dsp/helpers.hpp"


template<size_t N>
void energy_verification(const reson::core::Frame<N>& frame, const reson::core::Spectre<N>& spectre) {
    float time_domain_energy = 0.0f;
    for (size_t i = 0; i < frame.length(); ++i) {
        time_domain_energy += frame[i] * frame[i];
    }

    float freq_domain_energy = 0.0f;
    auto freq_energies = reson::dsp::power_spectrum(spectre);
    for (const auto& energy : freq_energies) {
        freq_domain_energy += energy;
    }

    std::cout << "Time Domain Energy: " << time_domain_energy << std::endl;
    std::cout << "Frequency Domain Energy: " << freq_domain_energy << std::endl;
}

template<size_t N>
void single_sinus_verification(reson::core::Frame<N> &frame, float amplitude, float frequency, float sample_rate, reson::core::Spectre<N>& spectre) {
    frame = create_test_frame<N>(amplitude, frequency, sample_rate);

    reson::dsp::FFT<N> fft;
    fft.process(frame, spectre);

    size_t expected_bin = static_cast<size_t>((frequency * N) / sample_rate);
    float max_magnitude = 0.0f;
    size_t max_bin = 0;
    

    for (size_t i = 0; i < spectre.length(); ++i) {
        float magnitude = std::abs(spectre[i]);
        if (magnitude > max_magnitude) {
            max_magnitude = magnitude;
            max_bin = i;
        }
    }

    float detected_amplitude = (2.0f / N) * max_magnitude;

    std::cout << "Expected Amplitude: " << amplitude << std::endl;
    std::cout << "Detected Amplitude: " << detected_amplitude << std::endl;


    std::cout << "Expected Peak Bin: " << expected_bin << std::endl;
    std::cout << "Detected Peak Bin: " << max_bin << std::endl;
}

template<size_t N>
void impulse_response_verification(reson::core::Frame<N> &frame, reson::core::Spectre<N>& spectre) {
    frame.samples.fill(0.0f);
    frame[0] = 1.0f; // Impulse at the start

    reson::dsp::FFT<N> fft;
    fft.process(frame, spectre);

    std::cout << "Impulse Response FFT Magnitudes:" << std::endl;
    for (size_t i = 0; i < spectre.length(); ++i) {
        std::cout << "Bin " << i << ": " << std::abs(spectre[i]) << std::endl;
    }
}


template<size_t N> 
void constant_signal_verification(reson::core::Frame<N> &frame, reson::core::Spectre<N>& spectre) {
    frame.samples.fill(1.0f); // Constant signal

    reson::dsp::FFT<N> fft;
    fft.process(frame, spectre);

    std::cout << "Constant Signal FFT Magnitudes:" << std::endl;
    for (size_t i = 0; i < spectre.length(); ++i) {
        std::cout << "Bin " << i << ": " << std::abs(spectre[i]) << std::endl;
    }
}

int main() {
    const size_t N = 512;
    reson::core::Frame<N> frame;
    reson::core::Spectre<N> spectre;

    constant_signal_verification<N>(frame, spectre);
    energy_verification<N>(frame, spectre);
    std::cout << "FFT processed successfully!" << std::endl;
    return 0;
}
