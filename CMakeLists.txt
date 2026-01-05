cmake_minimum_required(VERSION 3.20)
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
