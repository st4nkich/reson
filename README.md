# reson
Header-only C++ MFCC pipeline with Python bindings for audio feature extraction.

This library provides a lightweight, header-only implementation of a Mel-Frequency Cepstral Coefficients (MFCC) pipeline in C++. It supports common audio preprocessing steps including FFT, power spectrum, Mel filterbank, log compression, and DCT with orthogonal normalization.

The library also includes Python bindings via Pybind11, enabling seamless integration into Python workflows for audio analysis, feature extraction, and machine learning pipelines. It comes with ready-to-use signal generators (sinusoids, impulses, ramps, DC, white noise) for testing and validation.

Features:

Header-only, template-based C++ MFCC pipeline

Orthogonal DCT computation

Normalized Mel filterbanks

Python bindings via Pybind11

Built-in signal generators for testing

Suitable for ML pipelines and audio preprocessing
