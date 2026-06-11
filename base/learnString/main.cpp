#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::system("chcp 65001");

    //string字符串的find用法
    {
        std::string text = "The quick brown fox jumps over the lazy dog.";
        std::string word = "fox";

        size_t pos = text.find(word);
        if (pos != std::string::npos) {
            std::cout << "find '" << word << "' is: " << pos << std::endl;
        } else {
            std::cout << "'" << word << "' not found." << std::endl;
        }
    }

    //替换，replace用法
    {
        std::string  text = "I like cats.";
        std::string from = "cats";
        std::string to = "dogs";
        size_t pos = text.find(from);
        if (pos != std::string::npos) {
            text.replace(pos, from.length(), to);
            std::cout << "after replace: " << text << std::endl; // 输出: I like dogs.
        }
        else {
            std::cout << "'" << from << "' not found." << std::endl;
        }
    }

    //使用 substr() 获取子字符串
    {
        std::string str = "Hello, World!";
        std::string sub = str.substr(7, 5);// 从位置7开始，长度5
        std::cout << sub << std::endl;// 输出: World
        std::string sub2 = str.substr(7); // 从位置7开始直到结束
        std::cout << sub2 << std::endl; // 输出: World!
    }


    //使用 at() 函数（包含边界检查）
    {
        std::string str = "ABCDE";
        try {
            char c = str.at(10);// 超出范围，会抛出异常
        }catch (const std::out_of_range& e) {
            std::cout << "异常捕获: " << e.what() << std::endl;
        }
    }

    //结合std::transform转换大小写
    {
        //转为大写
        std::string str = "Hello, World!";
        std::transform(str.begin(), str.end(), str.begin(),[](unsigned char c) {
            return std::toupper(c);
        });
        std::cout << str << std::endl; // 输出: HELLO, WORLD!
        //转为小写
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        std::cout << str << std::endl; // 输出: hello, world!
    };

    //std::stringstream用法
    {
        std::stringstream ss;
        ss << "value: " << 42 << ", " << 3.14;
        std::string result = ss.str();
        std::cout << result << std::endl;// 输出: Value: 42, 3.14

        //从字符串流中读取数据
        std::string data = "123 45.67 Hello";
        std::stringstream ss2(data);
        int a;
        double b;
        std::string c;
        ss2 >> a >> b >> c;
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        // 输出: a: 123, b: 45.67, c: Hello
    }

    //从 C 风格字符串转换为 std::string
    {
        const char* cstr = "Hello, C-strings!";
        std::string str(cstr);
        std::cout << str << std::endl;  // 输出: Hello, C-strings!
    }

    //从 std::string 转换为 C 风格字符串
    {
        std::string str = "Hello, std::string!";
        const char* cstr = str.c_str();
        std::cout << cstr << std::endl;// 输出: Hello, std::string!
    }
    return 0;
}