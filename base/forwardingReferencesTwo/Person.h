//
// Created by yu'jie on 2026/5/27.
//

#ifndef FORWARDINGREFERENCESTWO_PERSON_H
#define FORWARDINGREFERENCESTWO_PERSON_H
//如何使用原样转发实现一个泛型工厂函数，完美转发构造函数的参数，以高效创建对象。
#include <iostream>
#include <string>
#include <utility>

class Person {
public:
    std::string name;
    int age;


    //左值引用构造函数
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Constructed Person(const std::string&, int)" << std::endl;
    }
    //右值引用构造函数
    Person(const std::string&& n, int a): name(std::move(n)), age(a) {
        std::cout << "Constructed Person(std::string&&, int)" << std::endl;
    }
};


//工厂函数，使用原样转发构造函数参数
template <typename T, typename... Args>
T create(Args&&... args) {
    return T(std::forward<Args>(args)...);
}

#endif //FORWARDINGREFERENCESTWO_PERSON_H
