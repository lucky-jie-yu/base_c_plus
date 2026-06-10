#include <iostream>
#include <type_traits>
#include <string>
#include <utility>
template <typename T>
void check_reference(T&& x) {
    std::cout << std::boolalpha;
    std::cout << "T is lvalue reference: " << std::is_lvalue_reference<T>::value << std::endl;
    std::cout << "T is rvalue reference: " << std::is_rvalue_reference<T>::value << std::endl;
    std::cout << "T is rvalue : " << std::is_rvalue_reference<T&&> ::value << std::endl;
    std::cout << "x is lvalue reference: " << std::is_lvalue_reference<decltype(x)>::value << std::endl;
    std::cout << "x is rvalue reference: " << std::is_rvalue_reference<decltype(x)>::value << std::endl;
}

template <typename T>
void display_type(T&& param) {
    std::cout << "type of T: " <<
        (std::is_lvalue_reference<T>::value ? "lvalue reference" : "rvalue reference")
    << ", " << (std::is_integral<typename std::remove_reference<T>::type>::value ? "Integral" : "Non-Integral")
    << std::endl;
}

//目标函数，分别存左值右值的重载
void process(const std::string& s) {
    std::cout << "Processing lvalue: " << s << std::endl;
}

void process(const std::string&& s) {
    std::cout << "Processing rvalue: " << s << std::endl;
}

//通用的包装函数，实现原样转发
template <typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg));
}
int main() {
    int a = 10;
    check_reference(a);  // T被推导为 int&， 因此 T&& -> int& && -> int&
    check_reference(10);   // T被推导为 int，  T&& -> int&&

    int&& c = 100;
    check_reference(c);   //实际中 T 被推导为 int&，这是因为 命名的右值引用变量在表达式中被视为左值。

    //为了让 T 被推导为右值引用，我们可以传递一个 真正的右值。这可以通过使用 std::move 来实现
    // std::move(c) 是右值，T 被推导为 int
    check_reference(std::move(c));

    std::cout << "******************************************" << std::endl;
    int x = 10;
    const int& y = x;
    display_type(x);            // T被推导为 int&
    display_type(20);           // T被推导为 int&&
    display_type(y);            // T被推导为 const int&
    display_type(std::move(x)); // T被推导为 int&&

    std::cout << "******************************************" << std::endl;
    //如何实现一个通用的wrapper函数，通过原样转发将参数传递给目标函数，同时保留参数的值类别。

    std::string name = "Alice";
    wrapper(name);   // 传递左值，调用process(const std::string&)
    wrapper("Bob");     // 传递右值，调用process(std::string&&)
    wrapper(std::move(name));  // 传递右值，调用process(std::string&&)
    return 0;
}
