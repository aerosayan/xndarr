cmake_minimum_required(VERSION 3.10)
project(xndarr)
add_executable(xndarr main.cpp)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_compile_features(xndarr PUBLIC cxx_std_14)

