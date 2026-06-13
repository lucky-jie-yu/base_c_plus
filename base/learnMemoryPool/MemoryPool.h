//
// Created by yu'jie on 2026/6/13.
//

#ifndef LEARNMEMORY_MEMORYPOOL_H
#define LEARNMEMORY_MEMORYPOOL_H
#include <stack>
#include <iostream>
class MemoryPool {
public:
    MemoryPool(size_t objSize, size_t totalSize);
    ~MemoryPool();
    void* allocate();
    void deallocate(void* ptr);
private:
    size_t objSize_;
    size_t totalSize_;
    char* pool_;
    std::stack<void*> freeList_;
};



#endif //LEARNMEMORY_MEMORYPOOL_H
