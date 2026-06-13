//
// Created by yu'jie on 2026/6/13.
//

#include "MemoryPool.h"



MemoryPool::MemoryPool(size_t objSize, size_t totalSize) : objSize_(objSize),
        totalSize_(totalSize), pool_((char*)malloc(objSize * totalSize)) {
    if (pool_ == nullptr) {
        std::__throw_bad_alloc();
    }
    for (size_t i = 0; i < totalSize_; ++i) {
        freeList_.push(pool_ + i * objSize);
    }
}

MemoryPool::~MemoryPool() {
    free(pool_);
}

void * MemoryPool::allocate() {
    if (freeList_.empty()) {
        std::__throw_bad_alloc();
    }
    void* ptr = freeList_.top();
    freeList_.pop();
    return ptr;
}

void MemoryPool::deallocate(void *ptr) {
    freeList_.push(ptr);
}
