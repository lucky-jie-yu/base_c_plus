#include <iostream>
#include <thread>
#include "SingletonOnceFlag.h"
#include <mutex>


int main() {

    system("chcp 65001");

    //共享智能指针懒汉式
    std::mutex mtx;
    std::thread t1([&]() {
        SingletonOnceFlag::getInstance();
        std::lock_guard<std::mutex> lock(mtx);
        SingletonOnceFlag::getInstance()->printAddress();
    });

    std::thread t2([&]() {
       SingletonOnceFlag::getInstance();
       std::lock_guard<std::mutex> lock(mtx);
       SingletonOnceFlag::getInstance()->printAddress();
   });

    t1.join();
    t2.join();//等到return 0 之后才会调用析构函数，所以输出的析构日志是这个的，不是下一个的

    std::cout << "************传递辅助函数回收内存*************" << std::endl;

    std::mutex mtx2;
    std::thread t3([&](){
        SingleAutoSafe::getInstance();
        std::lock_guard<std::mutex> lock(mtx2);
        SingleAutoSafe::getInstance()->PrintAddress();
    });

    std::thread t4([&](){
        SingleAutoSafe::getInstance();
        std::lock_guard<std::mutex> lock(mtx2);
        SingleAutoSafe::getInstance()->PrintAddress();
    });

    t3.join();
    t4.join();//不会调用自己的析构函数，因为是私有，等到shared_ptr为0时，会调用自定义的删除器delete到new出的内存
    return 0;
}
