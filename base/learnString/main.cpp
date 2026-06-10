#include <iostream>
#include <string>

int main() {

    //string字符串的find用法
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::string word = "fox";

    size_t pos = text.find(word);
    if (pos != std::string::npos) {
        std::cout << "找到 '" << word << "' 在位置: " << pos << std::endl;
    } else {
        std::cout << "'" << word << "' 未找到。" << std::endl;
    }

    return 0;
}