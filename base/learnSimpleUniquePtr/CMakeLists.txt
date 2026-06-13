cmake_minimum_required(VERSION 4.2)
project(learnSimpleUniquePtr)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnSimpleUniquePtr main.cpp
        SimpleUniquePtr.cpp
        SimpleUniquePtr.h
        Test.cpp
        Test.h)
