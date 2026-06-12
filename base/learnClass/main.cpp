#include <iostream>
#include <cstring>
class MyString {
private:
    char* data;// 动态分配的字符数组
public:
    //默认构造函数
    MyString() : data(nullptr){}
    //有参构造函数
    MyString(const char* str) {
        if (str) {
            int len = strlen(str) + 1;
            data = new char[len];
            strcpy(data, str);
        }
        else {
            data = nullptr;
        }
    }
    //拷贝构造
    MyString(const MyString& other) {
        if (other.data) {
            int len = strlen(other.data) + 1;
            data = new char[len];
            strcpy(data, other.data);
        }
        else {
            data = nullptr;
        }
    }

    //拷贝赋值
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;  // 释放原有内存
            if (other.data) {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    //比较运算符重载
    bool operator==(const MyString& other) const {
        if (data == nullptr && other.data == nullptr) {
            return true;
        }
        if (data == nullptr || other.data == nullptr) {
            return false;
        }
        return strcmp(data, other.data) == 0;
    }

    //输出运算重载
    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
        if (myStr.data) {
            os << myStr.data;
        }
        return os;
    }

    //析构函数
    ~MyString() {
        delete[] data;

    }
};
int main() {
    MyString str1("Hello World");
    MyString str2 = str1;// 拷贝构造
    MyString str3;
    str3 = str1;// 赋值运算符重载
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;
    if (str1 == str2) {
        std::cout << "str1 and str2 are equal." << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal." << std::endl;
    }
    return 0;
}
