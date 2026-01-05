#include "../include/features/mfcc_pipeline.hpp"
#include "generator.hpp"
#include <iostream>

template<size_t N>
void test_single_sinusoid(float amplitude, float frequency, float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_single_sinusoid_frame<N>(amplitude, frequency, sample_rate);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for single sinusoid (" << frequency << " Hz):" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_sum_sinusoids(const std::vector<float>& frequencies, float amplitude, float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_sum_sinusoids_frame<N>(frequencies, amplitude, sample_rate);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for sum of sinusoids: ";
    for (float f : frequencies) {
        std::cout << f << " Hz ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_impulse(float amplitude, float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_impulse_frame<N>(amplitude);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for impulse signal:" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_dc(float amplitude, float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_dc_frame<N>(amplitude);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for DC signal:" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_zero(float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_zero_frame<N>();

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for zero signal:" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_ramp(float start, float end, float sample_rate, int n_mels, int n_fft, int n_mfcc) {
    reson::core::Frame<N> frame = create_ramp_frame<N>(start, end);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for ramp signal:" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

template<size_t N>
void test_white_noise(float amplitude, float sample_rate, int n_mels, int n_fft, int n_mfcc) {

    reson::core::Frame<N> frame = create_white_noise_frame<N>(amplitude);

    MFCCPipeline<N> mfcc_pipeline(sample_rate, n_mels, n_fft, n_mfcc);
    std::vector<float> mfccs = mfcc_pipeline.process(frame);

    std::cout << "MFCCs for white noise signal:" << std::endl;
    for (size_t i = 0; i < mfccs.size(); ++i) {
        std::cout << "MFCC[" << i << "]: " << mfccs[i] << std::endl;
    }
    std::cout << std::endl;
}

int main(){

    const size_t N = 512;

    const float sample_rate = 16000.0f;
    const int n_mels = 40;
    const int n_fft = 512;
    const int n_mfcc = 13;

    test_single_sinusoid<N>(1.0f, 440.0f, sample_rate, n_mels, n_fft, n_mfcc);
    test_sum_sinusoids<N>({440.0f, 880.0f, 1760.0f}, 1.0f, sample_rate, n_mels, n_fft, n_mfcc);
    test_impulse<N>(1.0f, sample_rate, n_mels, n_fft, n_mfcc);
    test_dc<N>(1.0f, sample_rate, n_mels, n_fft, n_mfcc);
    test_zero<N>(sample_rate, n_mels, n_fft, n_mfcc);
    test_ramp<N>(0.0f, 1.0f, sample_rate, n_mels, n_fft, n_mfcc);
    test_white_noise<N>(1.0f, sample_rate, n_mels, n_fft, n_mfcc);

    return 0;
}