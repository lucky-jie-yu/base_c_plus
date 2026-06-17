#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
int main() {
    system("chcp 65001");
    //创建一个空的map,键为string,值为int
    std::map<std::string, int> ageMap;

    //插入键值对
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    //查找元素
    std::string name = "Bob";
    if (ageMap.find(name) != ageMap.end()) {
        std::cout << name << " 的年龄是 " << ageMap[name] << std::endl;
    }
    else {
        std::cout << "未找到 " << name << std::endl;
    }

    //遍历map
    std::cout << "所有人员和年龄：" << std::endl;
    for (auto it = ageMap.begin(); it != ageMap.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    //删除元素
    ageMap.erase("Alice");
    //打印删除后的map
    std::cout << "删除Alice后：" << std::endl;
    for (auto &[key, value] : ageMap) {
        std::cout << key << " : " << value << std::endl;
    }


    // 创建一个空的unordered_map，键为string，值为double
    std::unordered_map<std::string, double> priceMap;
    //插入键值对
    priceMap["Apple"] = 1.2;
    priceMap["Banana"] = 0.5;
    priceMap["Orange"] = 0.8;

    //查找元素
    std::string fruit = "Banana";
    if (priceMap.find(fruit) != priceMap.end()) {
        std::cout << fruit << " 的价格是 $" << priceMap[fruit] << std::endl;
    }
    else {
        std::cout << "未找到 " << fruit << std::endl;
    }

    //删除元素
    priceMap.erase("Apple");
    //打印删除后的unordered_map
    std::cout << "删除Apple后：" << std::endl;
    for (auto &[key, value] : priceMap) {
        std::cout << key << " : $" << value << std::endl;
    }
    return 0;
}
