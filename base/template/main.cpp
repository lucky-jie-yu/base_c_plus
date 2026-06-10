#include <iostream>
#include <vector>
#include <list>

template <template<typename, typename> class Container, typename T>
class ContainerPrinter {
public:
    void print(const Container<T, std::allocator<T>>& container) {
        for (const auto& elem : container) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

//基础情况,无参数
void printAll() {
    std::cout << std::endl;
}

// 递归情况，至少一个参数
 template <typename T, typename... Args>
 void printAll(const T& first, const Args&... args) {
     std::cout << first << " ";
     printAll(args...);//递归调用
 }


//使用折叠表达式版本
template <typename... Args>
void printAll(const Args&... args) {
    //使用左折叠展开参数包，并在每个参数后面输出一个空格
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

//折叠表达式，计算总和
template <typename... Args>
auto sum(Args... args) -> decltype((args + ...)) {
    return (args + ...);
}


//日志记录器
//基础情况，无参数
void log(const std::string& msg) {
    std::cout << msg << std::endl;
}

//递归情况，至少一个参数
template <typename T, typename... Args>
void log(const std::string& msg, const T& first, const Args&... args) {
    std::cout << msg << ": " << first << " ";
    log("", args...);
}
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> list = {10, 20 ,30};
    ContainerPrinter<std::vector, int>  vecPrinter;
    vecPrinter.print(vec);  // 输出：1 2 3 4 5
    ContainerPrinter<std::list, int> listPrinter;
    listPrinter.print(list);  // 输出：10 20 30


    //变参模板，递归打印所有参数
    printAll(1, 2.5, "hello", 'A');

    //计算总和
    std::cout << sum(1, 2, 3, 4) << std::endl;

    //日志记录器
    log("error",404,"Not Found");
    //输出Error,Not Found
    log("Sum ",             10, 20 ,30);

    return 0;
}
