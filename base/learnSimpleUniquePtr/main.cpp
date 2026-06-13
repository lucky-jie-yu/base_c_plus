#include <iostream>
#include "Test.h"
#include "SimpleUniquePtr.h"
int main() {
    //创建一个SimpleUniquePtr
    SimpleUniquePtr<Test> ptr(new Test(1));
    ptr->show();
    (*ptr).show();

    // 移动所有权到 ptr2
    SimpleUniquePtr<Test> ptr2 = std::move(ptr);
    if (ptr.get() == nullptr) {
        std::cout << "ptr1 is now nullptr after move." << std::endl;
    }
    ptr2->show();
    //释放所有权
    Test* rawPtr = ptr2.release();
    if (ptr2.get() == nullptr) {
        std::cout << "ptr2 is now nullptr after release." << std::endl;
    }
    rawPtr->show();
    delete rawPtr;

    //使用reset
    ptr2.reset(new Test(2));
    ptr2->show();

    ptr2.reset();
    if (ptr2.get() == nullptr) {
        std::cout << "ptr2 is now nullptr after reset." << std::endl;
    }
    return 0;
}
