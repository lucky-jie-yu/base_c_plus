//
// Created by yu'jie on 2026/6/17.
//

#ifndef LEARNDEQUE_DEQUE_H
#define LEARNDEQUE_DEQUE_H
#include "Iterator.h"
#include <stdexcept>
// 前置声明迭代器模板
template <typename T>
class Iterator;


template <typename T>
class Deque {
private:
    T* buffer; //内部缓冲区
    size_t capacity; //缓冲区容量
    size_t front_idx; //头部索引
    size_t back_idx; //尾部索引
    size_t count; //当前元素数量

    //调整容量
    void resize(size_t new_capacity) {
        T* new_buffer = new T[new_capacity];
        //重新排列元素
        for (size_t i = 0; i < count; ++i) {
            new_buffer[i] = buffer[(front_idx + i ) % capacity];
        }
        delete[] buffer;
        buffer = new_buffer;
        capacity = new_capacity;
        front_idx = 0;
        back_idx = count;
    }

    // 把迭代器设为友元，允许访问私有成员
    friend class Iterator<T>;
public:
    //构造函数
    Deque(size_t initial_capacity = 8) : capacity(initial_capacity), front_idx(0), back_idx(0),  count(0) {
        buffer = new T[capacity];
    }
    //析构函数
    ~Deque() {
        delete[] buffer;
    }

    //检查是否为空
    bool empty() const {
        return count == 0;
    }

    //获取大小
    size_t size() const {
        return count;
    }

    //在前面插入元素
    void push_front(const T& value) {
        if (count == capacity) {
            resize(capacity * 2);
        }
        front_idx = (front_idx == 0) ? capacity - 1 : front_idx - 1;
        buffer[front_idx] = value;
        ++count;
    }

    //在后面插入元素
    void push_back(const T& value) {
        if (count == capacity) {
            resize(capacity * 2);
        }
        buffer[back_idx] = value;
        back_idx = (back_idx + 1) % capacity;
        ++count;
    }

    //从前面删除元素
    void pop_front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        front_idx = (front_idx + 1) % capacity;
        --count;
    }

    //从后面删除元素
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        back_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1;
        --count;
    }

    //获取前端元素
    T& front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[front_idx];
    }

    const T& front() const{
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[front_idx];
    }

    //获取后端元素
    T& back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        size_t last_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1;
        return buffer[last_idx];
    }

    const T& back() const{
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        size_t last_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1;
        return buffer[last_idx];
    }


    //获取begin()迭代器
    Iterator<T> begin();
    //获取end()迭代器
    Iterator<T> end();
};

template<typename T>
Iterator<T> Deque<T>::begin() {
    return Iterator<T>(this, 0);
}

template<typename T>
Iterator<T> Deque<T>::end() {
    return Iterator<T>(this, count);
}


#endif //LEARNDEQUE_DEQUE_H
