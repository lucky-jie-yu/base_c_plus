#include <iostream>
#include <string>
int main() {
    system("chcp 65001");

    int a = 10; //a是一个左值
    int& b = a; //b是a的左值引用
    int && c = 20; //c是一个右值引用，绑定到临时右值20
    int d = a + 5; //(a + 5)是一个纯右值


    std::string s1 = "Hello"; //s1是一个左值
    std::string s2 = std::string("World"); // std::string("World")是一个纯右值

    std::cout << "a: " << a << ", d: " << d << std::endl;
    std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;

    //检查类型
    std::cout << std::boolalpha;
    //使用decltype((a))获取a的类型，包括引用
    //‘(a)'是一个左值表达式，所以decltype((a))是int&类型
    std::cout << "a是左值：" << std::is_lvalue_reference<decltype((a))>::value << std::endl;
    std::cout <<"c是右值引用 " << std::is_rvalue_reference<decltype(c)>::value << std::endl;
    return 0;
}
