#include <iostream>
#include <datastructures/dynamic_array.h>

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