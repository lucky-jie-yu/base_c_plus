cmake_minimum_required(VERSION 4.2)
project(learnInheritanceAndPolymorphism)

set(CMAKE_CXX_STANDARD 20)

add_executable(learnInheritanceAndPolymorphism main.cpp
        Vehicle.cpp
        Vehicle.h
        Base.cpp
        Base.h
        Shape.cpp
        Shape.h
)
