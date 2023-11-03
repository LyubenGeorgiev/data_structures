#include <datastructures/dynamic_array.h>
#include "catch2/catch_all.hpp"

TEST_CASE("test test")
{
	DynamicArray<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
    }

    for (int i = 0; i < arr.size(); ++i) {
		REQUIRE(arr[i] == i);
    }
}