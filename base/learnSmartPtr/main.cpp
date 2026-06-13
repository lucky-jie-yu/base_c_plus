#include <iostream>
#include <memory>
//双向关联导致循环引用
class B;// 前向声明
class A {
public:
    std::shared_ptr<B> ptrB;
    A() {
        std::cout << "A Constructor" << std::endl;
    }
    ~A() {
        std::cout << "A Destructor" << std::endl;
    }
};

class B {
public:
    //std::shared_ptr<A> ptrA;
    //改用 weak_ptr 其中一方（如 B 的 ptrA），打破循环引用。
    std::weak_ptr<A> ptrA;
    B() {
        std::cout << "B Constructor" << std::endl;
    }
    ~B() {
        std::cout << "B Destructor" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->ptrB = b;
    b->ptrA = a;
    std::cout << "Exiting main..." << std::endl;
    return 0;
}
