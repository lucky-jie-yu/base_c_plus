cmake_minimum_required(VERSION 4.2)
project(learnSimpleSharePtr)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnSimpleSharePtr main.cpp
        SimpleSharePtr.cpp
        SimpleSharePtr.h
        Test.cpp
        Test.h)
