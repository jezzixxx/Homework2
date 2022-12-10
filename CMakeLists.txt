cmake_minimum_required(VERSION 3.23)
project(DZ2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DZ2 main.cpp header.hpp encryption.cpp decryption.cpp)
