cmake_minimum_required(VERSION 4.2)
project(learnMemory)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnMemory main.cpp
        MemoryPool.cpp
        MemoryPool.h
        MyClass.cpp
        MyClass.h)
