#pragma once

#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
struct Node
{
    T data;
    Node * next;
    Node (const T& item):next(nullptr), data(item){}
};
template <typename T>
class LinkedList
{
private:
    Node<T> * head;
    size_t size;

public:
    LinkedList();
    ~LinkedList();
    void push_back(const T& element);
    void insertStart(const T& element);
    void insertPosition(const T& element, const int index);
    void removeIndex(const int index);
    void removeValue(const T& item);
    T* find(const T element);
    void resize();
    void sortElements();

    class iterator {
    private:
        Node<T>* ptr;

    public:
        iterator(Node<T>* p) : ptr(p) {}

        T& operator*() {
            return ptr->data;
        }

        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        bool operator!=(const iterator& other) {
            return ptr != other.ptr;
        }
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }
};
