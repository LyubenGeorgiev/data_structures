/*
  Copyright 2023 Lyuben Georgiev
  Implementation of Dynamic Array
*/

#pragma once

#include <cassert>


template <typename T>
class DoublyLinkedList {
public:
    struct DoublyLinkedListNode {
        T value;
        DoublyLinkedListNode* prev;
        DoublyLinkedListNode* next;

        DoublyLinkedListNode(T value, DoublyLinkedListNode* prev = nullptr, DoublyLinkedListNode* next = nullptr)
            : value(value), prev(prev), next(next) {}
    };

    // friend class iterator;
    // friend class const_iterator;

    class iterator {
    public:
        friend class DoublyLinkedList;
        bool operator== (const iterator& it) const {
            return ptr == it.ptr;
        }

        bool operator!= (const iterator& it) const {
            return !(operator==(it));
        }

        T& operator* () {
            return ptr->value;
        }

        const T& operator* () const {
            return ptr->value;
        }

        const iterator operator++ (int) const { // i++
            iterator toRet = (*this);
            ++(*this);
            return toRet;
        }

        iterator& operator++ () { // ++i
            ptr = ptr->next;

            return *this;
        }

        const iterator operator-- (int) const { // i--
            iterator toRet = (*this);
            --(*this);
            return toRet;
        }

        iterator& operator-- () { // --i
            ptr = ptr->prev;

            return *this;
        }

        iterator(DoublyLinkedListNode* ptr)
            : ptr(ptr) {}

    private:
        DoublyLinkedListNode* ptr;
    };

    class const_iterator {
    public:
        bool operator== (const const_iterator& it) const {
            return ptr == it.ptr;
        }

        bool operator!= (const const_iterator& it) const {
            return !(operator==(it));
        }

        const T& operator* () const {
            return ptr->value;
        }

        const const_iterator operator++ (int) const { // i++
            const_iterator toRet = (*this);
            ++(*this);
            return toRet;
        }

        const_iterator& operator++ () { // ++i
            ptr = ptr->next;

            return *this;
        }

        const const_iterator operator-- (int) const { // i--
            const_iterator toRet = (*this);
            --(*this);
            return toRet;
        }

        const_iterator& operator-- () { // --i
            ptr = ptr->prev;

            return *this;
        }

        const_iterator(DoublyLinkedListNode* ptr)
            : ptr(ptr) {}

    private:
        DoublyLinkedListNode* ptr;
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        return const_iterator(head);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(head);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

    DoublyLinkedList()
        : head(nullptr), tail(nullptr), sz(0) {
        ;
    }

    DoublyLinkedList(const DoublyLinkedList &other)
        : DoublyLinkedList() {
        copy(other);
    }

    DoublyLinkedList& operator= (const DoublyLinkedList &other) {
        if (this != &other) {
            free();
            copy(other);
        }

        return *this;
    }

    ~DoublyLinkedList() {
        free();
    }

    bool empty() const {
        return sz == 0;
    }

    std::size_t size() const {
        return sz;
    }

    const T& front() const {
        return head->value;
    }

    T& front() {
        return head->value;
    }

    const T& back() const {
        return tail->value;
    }

    T& back() {
        return tail->value;
    }

    void push_back(const T &element) {
        if (empty()) {
            head = tail = new DoublyLinkedListNode(element);
            sz = 1;
        } else {
            tail->next = new DoublyLinkedListNode(element, tail);
            tail = tail->next;
            ++sz;
        }
    }

    void pop_back() {
        assert(!empty());

        if (size() == 1) {
            delete head;
            head = tail = nullptr;
            sz = 0;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            --sz;
        }
    }

    void push_front(const T &element) {
        if (empty()) {
            head = tail = new DoublyLinkedListNode(element);
            sz = 1;
        } else {
            head->prev = new DoublyLinkedListNode(element, nullptr, head);
            head = head->prev;
            ++sz;
        }
    }

    void pop_front() {
        assert(!empty());

        if (size() == 1) {
            delete head;
            head = tail = nullptr;
            sz = 0;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            --sz;
        }
    }

    void erase(iterator it) {
        assert(!empty());

        if (size() == 1) {
            assert(it.ptr == head);

            pop_front();
        } else if (it.ptr == head) {
            pop_front();
        } else if (it.ptr == tail) {
            pop_back();
        } else {
            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;
            delete it.ptr;
        }
    }
    
private:
    // TODO
    void copy(const DoublyLinkedList &other) {
        DoublyLinkedListNode* cur = other.head;

        while (cur) {
            push_back(cur->value);
            cur = cur->next;
        }
    }

    void free() {
        DoublyLinkedListNode* cur = head;

        while (cur) {
            DoublyLinkedListNode* toDel = cur;
            cur = cur->next;
            delete toDel;
        }

        head = tail = nullptr;
        sz = 0;
    }

private:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
    std::size_t sz;

};