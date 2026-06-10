#include <iostream>
#include "Person.h"
int main() {
    std::string name = "Alice";
    //传递左值
    Person p1 = create<Person>(name, 30);
    //传递右值
    Person p2 = create<Person>(std::string("Bob"),25);
    return 0;
}
