#include <iostream>
#include "Single2.h"
#include <thread>

int main() {

    system("chcp 65001");

    // 通过方式一调用单例
    std::cout << "**********局部静态变量方式实现单例模式*********" << std::endl;
     std::cout << "s1 addr is " << &Single2::GetInst() << std::endl;
     std::cout << "s2 addr is " << &Single2::GetInst() << std::endl;


     std::cout << "***********通过静态成员变量指针方式，饿汉式**************" << std::endl;
     //通过方式二调用单例
     test_single2hungry();


     std::cout << "************静态成员变量指针方式，懒汉式****************" << std::endl;
    //通过方式三调用单例
    test_singlelazy();

    std::cout << "***无论饿汉式还是懒汉式都存在一个问题，就是什么时候释放内存？"
                 "多线程情况下，释放内存就很难了，还有二次释放内存的风险。" << std::endl;

    //方式二和方式三生成的单例对象的内存空间还没回收，这是个问题，另外如果多线程情况下多次delete也会造成崩溃。
    std::cout << "*****************************************" << std::endl;
    //利用C++11 提供的once_flag实现安全的创建测试
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
    t2.join();
    return 0;
}
