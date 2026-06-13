//
// Created by yu'jie on 2026/6/13.
//

#ifndef LEARNSIMPLESHAREPTR_SIMPLESHAREPTR_H
#define LEARNSIMPLESHAREPTR_SIMPLESHAREPTR_H
#include <iostream>
//控制块结构
struct ControlBlock {
    int ref_count;
    ControlBlock();
};

inline ControlBlock::ControlBlock() : ref_count(1){}

//简化版得shared_ptr实现
template <typename T>
class SimpleSharePtr {
public:
    //默认构造函数
    SimpleSharePtr();

    //有参构造函数
    SimpleSharePtr(T* ptr);

    //拷贝构造
    SimpleSharePtr(const SimpleSharePtr& other);

    //拷贝赋值
    SimpleSharePtr& operator=(const SimpleSharePtr& other);

    //移动构造
    SimpleSharePtr(SimpleSharePtr && other) noexcept;

    //移动赋值
    SimpleSharePtr& operator=(SimpleSharePtr&& other) noexcept;

    //析构函数
    ~SimpleSharePtr();

    //解引用操作符
    T& operator*() const;

    //箭头操作符
    T* operator->() const;

    //获取引用计数
    int use_count() const;

    //获取裸指针
    T* get() const;

    //重置指针
    void reset(T* p = nullptr);
private:
    T* ptr;   // 指向管理的对象
    ControlBlock* control;  // 指向控制块
    //释放当前资源
    void release();
};

template<typename T>
SimpleSharePtr<T>::SimpleSharePtr() : ptr(nullptr), control(nullptr){
    std::cout << "Default constructed SimpleSharedPtr (nullptr)." << std::endl;
}

template<typename T>
SimpleSharePtr<T>::SimpleSharePtr(T *p) : ptr(p) {
    if (p) {
        control = new ControlBlock();
        std::cout << "Constructed SimpleSharedPtr, ref_count = " << control->ref_count << std::endl;
    }
    else {
        control = nullptr;
    }
}

template<typename T>
SimpleSharePtr<T>::SimpleSharePtr(const SimpleSharePtr &other) : ptr(other.ptr), control(other.control) {
   if (control) {
       control->ref_count++;
       std::cout << "Copied SimpleSharedPtr, ref_count = " << control->ref_count << std::endl;
   }

}

template<typename T>
SimpleSharePtr<T> & SimpleSharePtr<T>::operator=(const SimpleSharePtr &other) {
    if (this != &other) {
        release();
        ptr = other.ptr;
        control = other.control;
        if (control) {
            control->ref_count++;
            std::cout << "Assigned SimpleSharedPtr, ref_count = " << control->ref_count << std::endl;
        }
    }
    return *this;
}

template<typename T>
SimpleSharePtr<T>::SimpleSharePtr(SimpleSharePtr &&other) noexcept : ptr(other.ptr), control(other.control) {
    other.ptr = nullptr;
    other.control = nullptr;
    std::cout << "Moved SimpleSharedPtr." << std::endl;
}

template<typename T>
SimpleSharePtr<T> & SimpleSharePtr<T>::operator=(SimpleSharePtr &&other) noexcept {
    if (this != &other) {
        release();
        ptr = other.ptr;
        control = other.control;
        ptr = nullptr;
        control = nullptr;
        std::cout << "Move-assigned SimpleSharedPtr." << std::endl;
    }
    return *this;
}

template<typename T>
SimpleSharePtr<T>::~SimpleSharePtr() {
    release();
}

template<typename T>
T & SimpleSharePtr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T * SimpleSharePtr<T>::operator->() const {
    return ptr;
}

template<typename T>
int SimpleSharePtr<T>::use_count() const {
    return control ? control->ref_count : 0;
}

template<typename T>
T * SimpleSharePtr<T>::get() const {
    return ptr;
}

template<typename T>
void SimpleSharePtr<T>::reset(T *p) {
    release();
    ptr = p;
    if (p) {
        control = new ControlBlock();
        std::cout << "Reset SimpleSharedPtr, ref_count = " << control->ref_count << std::endl;
    }
    else {
        control = nullptr;
    }
}

template<typename T>
void SimpleSharePtr<T>::release() {
    if (control) {
        control->ref_count--;
        std::cout << "Decremented ref_count to " << control->ref_count << std::endl;
        if (control->ref_count == 0) {
            delete control;
            delete ptr;
            std::cout << "Resource and ControlBlock destroyed." << std::endl;
        }
    }
    ptr = nullptr;
    control = nullptr;
}


#endif //LEARNSIMPLESHAREPTR_SIMPLESHAREPTR_H
