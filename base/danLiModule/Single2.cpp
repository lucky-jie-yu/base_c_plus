//
// Created by yu'jie on 2026/5/25.
//

#include "Single2.h"
#include <thread>
//饿汉式初始化
Single2Hungry * Single2Hungry::single = Single2Hungry::GetInst();


//线程i创建单例(方式二）
void thread_func_s2(int i ) {
    std::cout << "this is thread " << i << std::endl;
    std::cout << "inst is " << Single2Hungry::GetInst() << std::endl;
}

void test_single2hungry() {
    std::cout << "s1 addr is " << Single2Hungry::GetInst() << std::endl;
    std::cout << "s2 addr is " << Single2Hungry::GetInst() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::thread tid(thread_func_s2, i);
        tid.join();
    }
}


//懒汉式初试化
SinglePointer* SinglePointer::single = nullptr;
std::mutex SinglePointer::s_mutex;

//懒汉式线程i
void thread_func_lazy(int i) {
    std::cout << "this is lazy thread " << i << std::endl;
    std::cout << "inst is " << SinglePointer::GetInst() << std::endl;
}


//测试多线程懒汉式调用
void test_singlelazy() {
    for (int i = 0; i < 3; i++) {
        std::thread tid(thread_func_lazy, i);
        tid.join();
    }
    //何时释放new的对象？造成内存泄漏
}


//利用C++11 提供的once_flag实现安全的创建中static成员初始化
SingletonOnceFlag* SingletonOnceFlag::_instance = nullptr;

