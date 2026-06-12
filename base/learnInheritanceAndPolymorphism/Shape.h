//
// Created by yu'jie on 2026/6/12.
//

#ifndef LEARNINHERITANCEANDPOLYMORPHISM_SHAPE_H
#define LEARNINHERITANCEANDPOLYMORPHISM_SHAPE_H
#include <iostream>

//基类
class Shape {
public:
    virtual void draw() const{
        std::cout << "drawing a shape" << std::endl;
    }
    virtual ~Shape() {
        std::cout << "deleting a shape" << std::endl;
    }
};
//子类
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "drawing a circle" << std::endl;
    }
};
//子类
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "drawing a square" << std::endl;
    }
};
#endif //LEARNINHERITANCEANDPOLYMORPHISM_SHAPE_H
