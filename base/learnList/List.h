//
// Created by yu'jie on 2026/6/16.
//

#ifndef LEARNLIST_LIST_H
#define LEARNLIST_LIST_H
#include "Node.h"
#include "Iterator.h"
#include <iostream>
template <typename T>
class List {
public:
    using iterator = Iterator<T>;
    using const_iterator = Iterator<T>;

    //构造函数
    List() {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
    }
    //析构函数
    ~List() {
        clear();
        delete head;
        delete tail;
    }

    //禁止拷贝构造和赋值操作
    List(const List& other) = delete;
    List& operator=(const List& other) = delete;


    // 插入元素到迭代器位置之前
    iterator insert(iterator pos, const T& value) {
        Node<T>* current = pos.node_ptr;
        Node<T>* new_node = new Node<T>(value);

        Node<T>* prev_node = current->prev;

        new_node->next = current;
        new_node->prev = prev_node;
        prev_node->next = new_node;
        current->prev = new_node;

        return iterator(new_node);
    }


    // 删除迭代器指向的元素
    iterator erase(iterator pos) {
        Node<T>* current = pos.node_ptr;
        if (current == head || current == tail) {
            return pos;
        }
        Node<T>* prev_node = current->prev;
        Node<T>* next_node = current->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete current;
        return iterator(next_node);
    }


    //在头部插入元素
    void push_front(const T& value) {
        insert(begin(), value);
    }

    //在尾部插入元素
    void push_back(const T& value) {
        insert(end(), value);
    }

    // 在头部删除元素
    void pop_front() {
        if (!empty()) {
            erase(begin());
        }
    }

     // 在尾部删除元素
    void pop_back() {
        if (!empty()) {
            iterator temp = end();
            --temp;
            erase(temp);
        }
    }

    // 获取头元素引用
    T& front() {
        return head->next->data;
    }

    // 获取尾元素引用
    T& back() {
        return tail->prev->data;
    }

    // 判断是否为空
    bool empty() const{
        return head->next == tail;
    }

    // 获取链表大小（O(n)复杂度）
    size_t size() const {
        size_t count = 0;
        for (auto it = begin(); it != end(); ++it) {
            ++count;
        }
        return count;
    }


    // 清空链表
    void clear() {
        Node<T>* current = head->next;
        while (current != tail) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head->next = tail;
        tail->prev = head;
    }

    // 获取开始迭代器
    iterator begin() {
        return iterator(head->next);
    }

    // 获取结束迭代器
    iterator end() {
        return iterator(tail);
    }

    // 打印链表（辅助函数）
    void print() const {
        Node<T>* current = head->next;
        while (current != tail) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
private:
    Node<T>* head;//头哨兵
    Node<T>* tail;//尾哨兵
};


#endif //LEARNLIST_LIST_H
