/*
  Copyright 2023 Lyuben Georgiev
  Tests for the implementation of Dynamic Array
*/

#include <datastructures/doubly_linked_list.hpp>
#include "catch2/catch_all.hpp"

TEST_CASE("test linked list") {
    DoublyLinkedList<int> list;

    for (int i = 9; i >= 0; --i) {
        list.push_front(i);
    }
    for (int i = 10; i < 20; ++i) {
        list.push_back(i);
    }

    int i = 0;

    const DoublyLinkedList<int> constList = list;

    for (int num : constList) {
        REQUIRE(num == i);
        ++i;
    }
}
