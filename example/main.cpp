/*
  Copyright 2023 Lyuben Georgiev
  Simple example for library usage
*/

#include <iostream>
#include <vector>
#include <datastructures/dynamic_array.hpp>

int main() {
    DynamicArray<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
    }

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }

    return 0;
}
