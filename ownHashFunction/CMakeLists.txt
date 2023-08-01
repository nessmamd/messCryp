cmake_minimum_required(VERSION 3.26)
project(ownHashFunction)

set(CMAKE_CXX_STANDARD 17)

add_executable(ownHashFunction main.cpp
        hashfunction.cpp
        hashfunction.h)
