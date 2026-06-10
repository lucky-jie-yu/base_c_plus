//
// Created by yu'jie on 2026/5/25.
//

#ifndef DANLIMODULE_SINGLE2_H
#define DANLIMODULE_SINGLE2_H
#include <mutex>
#include <iostream>

//方式一：局部静态变量方式实现单例模式
//通过静态成员变量实现单例，懒汉式
class Single2 {
private:
    Single2() = default;//默认构造
    Single2(const Single2&) = delete;//删除拷贝构造
    Single2& operator=(const Single2&) = delete; // 删除拷贝赋值

public:
    //通过局部静态成员变量实现单例，该变量生命周期随进程结束而结束
    static Single2& GetInst() {
        static Single2 single;
        return single;
    }
};


//方式二：通过静态成员变量指针方式，饿汉式
//依靠静态成员变量提前初试化保证生成的单例是唯一的
class  Single2Hungry {
private:
    Single2Hungry() = default;
    Single2Hungry(const Single2Hungry&) = delete;
    Single2Hungry& operator=(const Single2Hungry&) = delete;
    static Single2Hungry * single;

public:
    static Single2Hungry * GetInst() {
        if (single == nullptr) {
            single = new Single2Hungry();
        }
        return single;
    }


};


//方式三：静态成员变量指针方式（懒汉式）
//懒汉式指针
class SinglePointer {
private:
    SinglePointer() = default;
    SinglePointer(const SinglePointer&) = delete;
    SinglePointer& operator = (const SinglePointer&) = delete;
    static SinglePointer * single;
    static std::mutex s_mutex;
public:
    static SinglePointer * GetInst() {
        if (single != nullptr) {
            return single;
        }
        s_mutex.lock();
        if (single != nullptr) {
            s_mutex.unlock();
            return single;
        }
        single = new SinglePointer();
        s_mutex.unlock();
        return single;
    }
};


//利用C++11 提供的once_flag实现安全的创建
class SingletonOnceFlag {
private:
    SingletonOnceFlag() = default;
    SingletonOnceFlag(const SingletonOnceFlag&) = delete;
    SingletonOnceFlag& operator = (const SingletonOnceFlag&) = delete;
    static SingletonOnceFlag * _instance; //static 成员要在cpp中初始化

public:
    static SingletonOnceFlag * getInstance() {
        static std::once_flag flag;
        std::call_once(flag, [] {
            _instance = new SingletonOnceFlag();
        });
        return _instance;
    }
    void printAddress() {
        std::cout << _instance << std::endl;
    }
    ~SingletonOnceFlag() {
        std::cout << "this is singleton destruct" << std::endl;
    }
};

//线程i创建单例(方式二）
void thread_func_s2(int i );
//测试多线程饿汉式调用
void test_single2hungry();


//懒汉式线程i
void thread_func_lazy(int i);
//测试多线程懒汉式调用
void test_singlelazy();
#endif //DANLIMODULE_SINGLE2_H
