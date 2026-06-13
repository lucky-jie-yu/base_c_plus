//
// Created by yu'jie on 2026/6/13.
//

#ifndef LEARNSIMPLEUNIQUEPTR_TEST_H
#define LEARNSIMPLEUNIQUEPTR_TEST_H
#include <iostream>

class Test {
public:
    Test() = default;
    ~Test();
    Test(int val);
    void show() const;
private:
    int value;
};

inline Test::~Test() {
    std::cout << "Test Destructor: " << value << std::endl;
}

inline Test::Test(int val) : value(val) {
    std::cout << "Test Constructor: " << value << std::endl;
}

inline void Test::show() const {
    std::cout << "Value: " << value << std::endl;
}


#endif //LEARNSIMPLEUNIQUEPTR_TEST_H
