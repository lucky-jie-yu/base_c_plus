//
// Created by yu'jie on 2026/6/16.
//

#ifndef LEARNLIST_ITERATOR_H
#define LEARNLIST_ITERATOR_H
#include "Node.h"
#include <iostream>
#include <iterator>
template <typename T>
class List;

template <typename T>
class Iterator {
public:
    using self_type = Iterator<T>;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    Iterator(Node<T>* ptr = nullptr) : node_ptr(ptr){}

    // Dereference operator
    reference operator*() const {
        return node_ptr->data;
    }

    // Arrow operator
    pointer operator->() const {
        return &(node_ptr->data);
    }

    // Pre-increment
    self_type& operator++() {
        if (node_ptr) {
            node_ptr = node_ptr->next;
        }
        return *this;
    }

    // Post-increment
    self_type operator++(int) {
        self_type temp = *this;
        ++(*this);
        return temp;
    }

    // Pre-decrement
    self_type& operator--() {
        if (node_ptr) {
            node_ptr = node_ptr->prev;
        }
        return *this;
    }

    // Post-decrement
    self_type operator--(int) {
        self_type temp = *this;
        --(*this);
        return temp;
    }

    // Equality comparison
    bool operator==(const self_type& other) const {
        return node_ptr == other.node_ptr;
    }
    // Inequality comparison
    bool operator!=(const self_type& other) const {
        return node_ptr != other.node_ptr;
    }
private:
    Node<T>* node_ptr;
    friend class List<T>;
};


#endif //LEARNLIST_ITERATOR_H
