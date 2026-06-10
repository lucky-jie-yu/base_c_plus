#include <iostream>
#include <string>
int main() {
    //find 用法
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::string word = "fox";
    size_t pos = text.find(word);
    if (pos != std::string::npos) {
        std::cout << "find " << word << " is " << pos << std::endl;
    }
    else {
        std::cout << "not find!" << std::endl;
    }
    return 0;
}
