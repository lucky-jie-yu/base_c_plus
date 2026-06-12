//
// Created by yu'jie on 2026/6/12.
//

#ifndef LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
#define LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
#include <iostream>
//C++ 容器（如 std::vector、std::list 等） 通常存储对象的副本，
//而非指向对象的指针。因此，当与继承结合使用时，可能导致 切片（Object Slicing） 问题，
//即仅存储基类部分，丢失派生类特有的信息。为了实现多态性，推荐使用指针或智能指针存储对象。

class Base {
public:
    virtual void show() const{
        std::cout << "Base show" << std::endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived show" << std::endl;
    }
};
#endif //LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
