#include <iostream>
//返回引用
int& getMax(int& a, int& b) {
    if (a > b) {
        return a;
    }
    return b;
}

//返回指针
int* allocateArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
    return arr;
}

//尾递归是指递归调用在函数的最后一步，可以被编译器优化为循环，减少堆栈消耗。
//辅助函数，用于尾递归
long long factorialHelper(int n, long long accumulator) {
    if (n == 0) {
        return accumulator;
    }
    return factorialHelper(n - 1, n * accumulator);
}

//尾递归函数
long long factorial(int n) {
    return factorialHelper(n, 1);
}


//普通函数
void greet() {
    std::cout << "Hello from greet!" << std::endl;
}

//函数指针作为参数
// 高阶函数，接受函数指针作为参数
void execute(void (*funcPtr) ()) {
    funcPtr();
}

//被调用函数
void sayHi() {
    std::cout << "Hi!" << std::endl;
}

//回调类型定义
typedef void (*CallBack)();

//函数接收回调
void registerCallBack(CallBack cb) {
    std::cout << "Before callback" << std::endl;
    cb(); // 执行回调
    std::cout << "After callback" << std::endl;
}

//回调函数
void myCallBack() {
    std::cout << "Callback executed!" << std::endl;
}
int main() {
    {
        int x = 10;
        int y = 20;
        int& max = getMax(x, y);
        std::cout << "max :" << max << std::endl;
        max = 30;
        std::cout << "y :" << y << std::endl;
    }
    {
        int size = 5;
        int* myArray = allocateArray(size);
        for (int i = 0; i < size; i++) {
            std::cout << myArray[i] << " ";
        }
        std::cout << std::endl;
        delete [] myArray;
    }

    //尾递归阶乘
    {
        int number = 5;
        std::cout << number << "! = " << factorial(number) << std::endl;
    }

    //定义函数指针
    {
        void (*funcPtr)() = greet;
        // 通过指针调用函数
        funcPtr();
    }
    //调用函数指针
    {
        execute(sayHi);
    }

    //回调函数：通过函数指针传递的函数，通常用于在特定事件发生时执行自定义操作。
    {
        registerCallBack(myCallBack);
    }
    return 0;
}
