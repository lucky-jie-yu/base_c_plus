#include <iostream>
#include <vector>
int main() {
    //迭代器类型
    {
        std::vector<int>::iterator it;// 迭代器it, it能读写vector<int>的元素
        std::string::iterator it2;// it2能读写string对象的字符
        std::string::const_iterator it3; // it3只能读元素，不能写元
        std::string::const_iterator it4; //// it4只能读字符,不能写字符
    }

    //erase会返回删除元素的下一个元素的迭代器
    //erase的应用
    //vector容器存储了一系列数字，在循环中遍历每一个元素，
    //并且删除其中的奇数，要求循环结束，vector元素为偶数，要求时间复杂度o(n)
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        for (auto it = numbers.begin(); it != numbers.end(); ) {
            if ((*it) % 2 != 0) {
                it = numbers.erase(it);
                continue;
            }
            ++it;
        }
        for(auto num : numbers) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
    return 0;
}
