cmake_minimum_required(VERSION 4.2)
project(learnList)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnList main.cpp
        Node.cpp
        Node.h
        Iterator.cpp
        Iterator.h
        List.cpp
        List.h)
