//
// Created by yu'jie on 2026/6/13.
//

#include "MyClass.h"
#include <iostream>
MyClass::MyClass(int val) : value(val){
    std::cout << "MyClass constructor: " << value << std::endl;
}

MyClass::~MyClass() {
    std::cout << "MyClass destructor: " << value << std::endl;
}


