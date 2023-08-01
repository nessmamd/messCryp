cmake_minimum_required(VERSION 3.26)
project(CryptoBISMALLAH)

set(CMAKE_CXX_STANDARD 17)

add_executable(CryptoBISMALLAH main.cpp
        Block.h
        Blockchain.h
        sha256.h
        sha256.cpp
        Block.cpp
        Blockchain.cpp
        enhash.h
        enhash.cpp
)
