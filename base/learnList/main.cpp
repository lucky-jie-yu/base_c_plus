#include <iostream>
#include "Iterator.h"
#include "List.h"
#include "Node.h"
int main() {
    system("chcp 65001");
    List<int> lst;
    //插入元素
    lst.push_back(10);  // 链表: 10
    lst.push_front(5);   // 链表: 5, 10
    lst.push_front(15);   // 链表: 15, 5, 10,
    lst.insert(++lst.begin(), 7);  // 链表: 15, 7, 5, 10

    // 打印链表
    std::cout << "链表内容: ";
    lst.print(); // 输出: 15, 7, 5, 10

    // 删除元素
    lst.pop_front(); // 链表: 7, 5 ,10
    lst.pop_back();  // 链表: 7, 5

    // 打印链表
    std::cout << "删除头尾后链表内容: ";
    lst.print(); // 输出: 7, 5


    // 插入和删除
    auto it = lst.begin();
    lst.insert(it, 3);  // 链表: 3, 7, 5,insert返回的新迭代器只是临时值，你没存到任何变量，
                            //  原来的变量 it 自始至终没变，依然指向原来的节点（7）
    lst.erase(++it);    // 链表: 3, 7

    // 打印链表
    std::cout << "插入和删除后链表内容: ";
    lst.print(); // 输出: 3, 7

    // 清空链表
    lst.clear();
    std::cout << "清空后，链表是否为空: " << (lst.empty() ? "是" : "否") << std::endl;
    return 0;
}
