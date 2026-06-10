//
// Created by yu'jie on 2026/5/26.
//

#ifndef TONGYONGDANLIMOUDLECLASS_DEMO_H
#define TONGYONGDANLIMOUDLECLASS_DEMO_H
#include <iostream>
#include <mutex>
#include <memory>
template <typename T>
class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance() {
        static std::once_flag s_flag;
        std::call_once(s_flag,[&]() {
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }
    void printAddress() {
        std::cout << _instance.get() << std::endl;
    }
    ~Singleton() {
        std::cout << "this is singleton destruct" << std::endl;
    }
};
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;



//通过继承方式实现网络模块单例
class SingleNet : public Singleton<SingleNet> {
    friend class Singleton<SingleNet>;
private:
    SingleNet() = default;
public:
    ~SingleNet() {
        std::cout << "SingleNet destruct " << std::endl;
    }
};

#endif //TONGYONGDANLIMOUDLECLASS_DEMO_H
