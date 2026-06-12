#include <iostream>
#include "Vehicle.h"
#include "Base.h"
#include "Shape.h"
#include <vector>


int main() {
    {
        Shape shape;
        Circle circle;
        Square square;
        shape.draw();
        circle.draw();
        square.draw();
    }
    std::cout << "*******************************" << std::endl;
    // 纯虚类与抽象基类
    // Vehicle v; // 错误: 不能实例化抽象类
    {
        Car car;
        Motorcycle motorcycle;
        car.startEngine(); // 输出: Car engine started.
        motorcycle.startEngine();// 输出: Motorcycle engine started.]
        Vehicle* v1 = &car;
        Vehicle* v2 = &motorcycle;
        v1->startEngine(); // 动态绑定，输出: Car engine started.
        v2->startEngine(); // 动态绑定，输出: Motorcycle engine started.
    }

    // 切片问题
    {
        std::vector<Base> vec;
        Derived d;
        vec.push_back(d); // 切片发生，派生类特有部分被丢弃

        vec[0].show(); // 输出: Base show
    }

        //使用智能指针避免切片
    {
        std::vector<std::unique_ptr<Base>> vec;
        vec.emplace_back(std::make_unique<Derived>());

        vec[0]->show(); // 输出: Derived show
    }


    return 0;
}
