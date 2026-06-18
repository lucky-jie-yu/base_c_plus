// Iterator.h
//
// Created by yu'jie on 2026/6/18.
//
#ifndef LEARNDEQUE_ITERATOR_H
#define LEARNDEQUE_ITERATOR_H
#include <iterator>

// 前置声明Deque模板，不再包含Deque.h，彻底切断循环包含
template <typename T>
class Deque;

template <typename T>
class Iterator {
private:
    Deque<T>* deque_ptr;
    size_t pos;  // 相对头部偏移量
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = T;
    using difference_type   = ptrdiff_t;  // 双向迭代器必须用有符号类型，不能size_t
    using pointer           = T*;
    using reference         = T&;

    Iterator(Deque<T>* deque, size_t position) : deque_ptr(deque), pos(position) {}

    reference operator*() const {
        size_t real_idx = (deque_ptr->front_idx + pos) % deque_ptr->capacity;
        return deque_ptr->buffer[real_idx];
    }

    pointer operator->() const {
        size_t real_idx = (deque_ptr->front_idx + pos) % deque_ptr->capacity;
        return &(deque_ptr->buffer[real_idx]);
    }

    // 前置++
    Iterator& operator++() {
        ++pos;
        return *this;
    }
    // 后置++
    Iterator operator++(int) {
        Iterator temp = *this;
        ++pos;
        return temp;
    }

    // 前置--
    Iterator& operator--() {
        --pos;
        return *this;
    }
    // 后置--
    Iterator operator--(int) {
        Iterator temp = *this;
        --pos;
        return temp;
    }

    bool operator==(const Iterator& other) const {
        return deque_ptr == other.deque_ptr && pos == other.pos;
    }
    // 修复 != 逻辑：取反相等判断
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }

    // 删除原来写在这里的 begin() end()！迭代器不能包含这两个函数
};

#endif //LEARNDEQUE_ITERATOR_H