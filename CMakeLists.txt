cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0148 NEW)
project(reson LANGUAGES CXX)

# --- C++ standard ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)  # za shared library

# --- Pybind11 ---
find_package(pybind11 REQUIRED)

# --- Include directories ---
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Source files ---
set(SRC_FILES
    bindings/python_module.cpp
)

# --- Build pybind11 module ---
pybind11_add_module(reson ${SRC_FILES})

# --- Optional: target include dirs (modern CMake) ---
target_include_directories(reson PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Build tests ---
add_executable(fft_test tests/fft_test.cpp)
target_include_directories(fft_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_executable(pipeline_test tests/pipeline_test.cpp)
target_include_directories(pipeline_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_executable(window_test tests/window_test.cpp)
target_include_directories(window_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/tests)
