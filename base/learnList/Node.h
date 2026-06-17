//
// Created by yu'jie on 2026/6/16.
//

#ifndef LEARNLIST_NODE_H
#define LEARNLIST_NODE_H

template <typename T>
struct Node {
    T data;
    Node *next;
    Node *prev;
    explicit Node(const T& value = T()) : data(value), next(nullptr), prev(nullptr) {}
};


#endif //LEARNLIST_NODE_H
