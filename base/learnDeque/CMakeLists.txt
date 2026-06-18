cmake_minimum_required(VERSION 4.2)
project(learnDeque)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnDeque main.cpp
        Deque.cpp
        Deque.h
        Iterator.cpp
        Iterator.h)
