//
// Created by yu'jie on 2026/5/25.
//

#ifndef SMARTPOINTDANLIMODULE_SINGLETONONCEFLAG_H
#define SMARTPOINTDANLIMODULE_SINGLETONONCEFLAG_H
#include <iostream>
#include <memory>
#include <mutex>


//利用智能指针自动回收内存的机制设计单例类,懒汉式
class SingletonOnceFlag {
private:
    SingletonOnceFlag() = default;
    SingletonOnceFlag(const SingletonOnceFlag &) = delete;
    SingletonOnceFlag & operator = (const SingletonOnceFlag &) = delete;
    static std::shared_ptr<SingletonOnceFlag> _instance;

public:
    static std::shared_ptr<SingletonOnceFlag> getInstance() {
        static std::once_flag flag;
        std::call_once(flag, []() {
            _instance = std::shared_ptr<SingletonOnceFlag>(new SingletonOnceFlag());
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

//辅助类智能指针单例模式
//智能指针在构造的时候可以指定删除器，
//所以可以传递一个辅助类或者辅助函数帮助智能指针回收内存时调用我们指定的析构函数。
class SingleAutoSafe;
class SafeDeletor
{
public:
    void operator()(SingleAutoSafe *sf)
    {
        std::cout << "this is safe deleter operator()" << std::endl;
        delete sf;
    }
};

class SingleAutoSafe {
public:
    static std::shared_ptr<SingleAutoSafe>  getInstance() {
        static std::once_flag flag;
        std::call_once(flag , []() {
            _instance = std::shared_ptr<SingleAutoSafe>(new SingleAutoSafe(), SafeDeletor());
        });
        return _instance;
    }

    void PrintAddress() {
        std::cout << _instance << std::endl;
    }
    //定义友元类，通过友元类调用该类析构函数
    friend class SafeDeletor;
private:
    SingleAutoSafe() = default;
    SingleAutoSafe(const SingleAutoSafe &) = delete;
    SingleAutoSafe & operator = (const SingleAutoSafe &) = delete;
    ~SingleAutoSafe() {
        std::cout << "this is singleton destruct" << std::endl;
    }
    static std::shared_ptr<SingleAutoSafe> _instance;
};
#endif //SMARTPOINTDANLIMODULE_SINGLETONONCEFLAG_H
