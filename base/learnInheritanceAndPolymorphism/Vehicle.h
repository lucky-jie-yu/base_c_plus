//
// Created by yu'jie on 2026/6/12.
//

#ifndef LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
#define LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
#include <iostream>
//纯虚函数 是在基类中声明但不提供实现的虚函数。包含至少一个
//纯虚函数的类称为 抽象基类（Abstract Base Class，ABC）。
//抽象基类不能被实例化，要求派生类必须实现所有纯虚函数才能被实例化。

class Vehicle {
public:
    virtual void startEngine() = 0;// 纯虚函数
    virtual ~Vehicle()= default;  // 虚析构函数
};

class Car : public Vehicle {
public:
    void startEngine()  override {
        std::cout << "Car engine started." << std::endl;
    }
};


class Motorcycle : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Motorcycle started." << std::endl;
    }
};

#endif //LEARNINHERITANCEANDPOLYMORPHISM_BASE_H
