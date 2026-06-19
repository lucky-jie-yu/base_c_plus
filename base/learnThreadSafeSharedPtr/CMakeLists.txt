cmake_minimum_required(VERSION 4.2)
project(learnThreadSafeSharedPtr)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnThreadSafeSharedPtr main.cpp
        ThreadSafeSharedPtr.h
        Test.cpp
        Test.h)
