//
// Created by yu'jie on 2026/6/13.
//

#ifndef LEARNSIMPLESHAREPTR_TEST_H
#define LEARNSIMPLESHAREPTR_TEST_H
#include <iostream>

class Test {
public:
    Test() = default;
    Test(int val);
    ~Test();
    void show() const;
private:
    int value;
};

inline Test::Test(int val) : value(val){
    std::cout << "Test Constructor: " << value << std::endl;
}

inline Test::~Test() {
    std::cout << "Test Destructor: " << value << std::endl;
}

inline void Test::show() const {
    std::cout << "Value: " << value << std::endl;
}


#endif //LEARNSIMPLESHAREPTR_TEST_H
