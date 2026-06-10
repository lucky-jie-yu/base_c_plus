#include <iostream>
#include <thread>
#include <mutex>
#include "demo.h"

int main() {
    std::mutex mtx;
    std::thread t1([&]() {
        SingleNet::GetInstance();
        std::lock_guard<std::mutex> lock(mtx);
        SingleNet::GetInstance()->printAddress();
    });
    std::thread t2([&]() {
        SingleNet::GetInstance();
        std::lock_guard<std::mutex> lock(mtx);
        SingleNet::GetInstance()->printAddress();
    });
    t1.join();
    t2.join();
    return 0;
}
