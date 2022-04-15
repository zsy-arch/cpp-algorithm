cmake_minimum_required(VERSION 3.22)
project(cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(kmp kmp/main.cpp kmp/kmp.h)