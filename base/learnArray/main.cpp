#include <iostream>
#include <vector>
int main() {
    //C++11提供了获取最后元素的下一个位置的指针，以及指向首元素的指针
    {
        int ia[] = {0,1,2,3,4,5,6,7,8,9};
        int *beg = std::begin(ia);
        int *end = std::end(ia);
        for (auto it = beg; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    //使用数组初始化vector对象
    {
        int int_arr[] = {0,1,2,3,4,5};
        std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));
        for (auto e : ivec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
