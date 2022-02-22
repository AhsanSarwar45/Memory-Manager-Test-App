#include "MemoryManager/StackAllocator.hpp"

#include <iostream>

using namespace Memory;

int main()
{
    StackAllocator stackAllocator = StackAllocator(4, nullptr, 8, "MyCustomAllocator");

    int* num = stackAllocator.New<int>(5);

    std::cout << *num << "\n";
}