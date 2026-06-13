//
// Created by yu'jie on 2026/6/13.
//

#ifndef LEARNSIMPLEUNIQUEPTR_SIMPLEUNIQUEPTR_H
#define LEARNSIMPLEUNIQUEPTR_SIMPLEUNIQUEPTR_H

template <typename T>
class SimpleUniquePtr {
public:
    SimpleUniquePtr();
    SimpleUniquePtr(T* p);
    SimpleUniquePtr(const SimpleUniquePtr& other) = delete;
    SimpleUniquePtr& operator=(const SimpleUniquePtr& other) = delete;
    SimpleUniquePtr(SimpleUniquePtr&& other) noexcept;
    SimpleUniquePtr& operator =(SimpleUniquePtr&& other) noexcept;
    ~SimpleUniquePtr();
    T& operator*() const;
    T* operator->() const;
    T* get() const;
    //释放所有权
    T* release();
    void reset(T* p = nullptr);

private:
    T* ptr;
};

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr(): ptr(nullptr){}

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr(T *p) : ptr(p){}

template<typename T>
SimpleUniquePtr<T>::SimpleUniquePtr(SimpleUniquePtr &&other)  noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
}

template<typename T>
SimpleUniquePtr<T> & SimpleUniquePtr<T>::operator=(SimpleUniquePtr &&other) noexcept {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template<typename T>
SimpleUniquePtr<T>::~SimpleUniquePtr() {
    delete ptr;
}

template<typename T>
T & SimpleUniquePtr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T * SimpleUniquePtr<T>::operator->() const {
    return ptr;
}

template<typename T>
T * SimpleUniquePtr<T>::get() const {
    return ptr;
}

template<typename T>
T * SimpleUniquePtr<T>::release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}

template<typename T>
void SimpleUniquePtr<T>::reset(T *p) {
    delete ptr;
    ptr = p;
}


#endif //LEARNSIMPLEUNIQUEPTR_SIMPLEUNIQUEPTR_H
