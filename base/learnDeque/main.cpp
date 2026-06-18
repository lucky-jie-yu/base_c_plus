#include <iostream>
#include <string>
#include "Deque.h"
#include "Iterator.h"
int main() {
    system("chcp 65001");


    Deque<std::string> deque;

    // 在后面插入元素
    deque.push_back("Apple");
    deque.push_back("Banana");
    deque.push_back("Cherry");

    // 在前面插入元素
    deque.push_front("Date");
    deque.push_front("Elderberry");
    // 显示队列大小
    std::cout << "Deque 大小: " << deque.size() << std::endl;

    // 使用迭代器进行遍历
    std::cout << "Deque 元素: ";
    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 访问前端和后端元素
    std::cout << "前端元素: " << deque.front() << std::endl;
    std::cout << "后端元素: " << deque.back() << std::endl;
    // 删除元素
    deque.pop_front();
    deque.pop_back();

    // 再次遍历
    std::cout << "删除元素后的 Deque: ";
    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
