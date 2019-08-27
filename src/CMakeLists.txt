cmake_minimum_required(VERSION 3.10)
project(xndarr)
add_executable(xndarr main.cpp)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-O3 -Wall ")

target_compile_options(xndarr PUBLIC "--std=c++17")
target_compile_options(xndarr PUBLIC "-mavx2")

