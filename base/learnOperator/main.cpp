#include <iostream>
 //运算符可以作为成员函数或友元函数进行重载


class Complex {
public:
    double real;
    double imag;

    Complex (double r = 0, double i = 0) : real(r), imag(i){}
    //成员函数重载
    Complex operator+(const Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    //友元函数重载
    friend Complex operator+(const Complex &c1, const Complex &c2) {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.imag = c1.imag + c2.imag;
        return temp;
    }

    // 重载 << 运算符（作为友元函数）
    friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};
int main() {
    Complex c1(1.2 ,3.4);
    Complex c2(5.6, 7.8);
    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;// 输出: c1 + c2 = 6.8 + 11.2i
    return 0;
}
