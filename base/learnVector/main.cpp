#include <iostream>
#include <vector>
int main() {
    //初始化
    {
        //默认初始化
        std::vector<int> vec1; //// 空向量
        //指定大小和默认值
        std::vector<int> vec2(5, 10);// 5个元素，值均为10
        //使用初始化列表
        std::vector<int> vec3 = {1, 2, 3, 4, 5};
        //拷贝构造
        std::vector<int> vec4(vec3);  // 复制vec3
        //移动构造
        std::vector<int> vec5(std::move(vec4));// 移动vec4到vec5
    }

    //向量的基本操作
    {
        std::vector<int> vec;
        // 使用push_back添加元素
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "After push_back: ";
        for (auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;// 输出: 10 20 30
        // 使用pop_back移除最后一个元素
        vec.pop_back();
        std::cout << "After pop_back: ";
        for(auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 10 20

        // 在第二个位置插入25
        vec.insert(vec.begin() + 1, 25);
        std::cout << "After insert: ";
        for(auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 10 25 20

        //删除第二个元素（25）
        vec.erase(vec.begin() + 1);
        std::cout << "After erase: ";
        for(auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 10 20

        // 清空向量
        vec.clear();
        std::cout << "After clear, size: " << vec.size() << std::endl; // 输出: 0
    }

    //使用reserve预留空间和shrink_to_fit()收缩空间
    {
        std::vector<int> vec;
        //预留较大空间
        vec.reserve(1000);
        std::cout << "Capacity before adding: " << vec.capacity() << std::endl;
        //添加少量元素
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        std::cout << "Size after adding: " << vec.size() << std::endl;
        std::cout << "Capacity after adding: " << vec.capacity() << std::endl;

        //收缩容量
        vec.shrink_to_fit();
        std::cout << "Capacity after shrink_to_fit: " << vec.capacity() << std::endl;
    }
    return 0;
}
