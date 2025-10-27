#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>
#include <functional>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class LinkedList {
private:
    struct Node {
        std::unique_ptr<Node> next;
        int data;
        Node() : next(nullptr), data(0) {}
        Node(int val) : next(nullptr), data(val) {}    
    };

    std::unique_ptr<Node> head;
    int size;

public:
    LinkedList();
    LinkedList(std::initializer_list<int> elements);
    
    void pushFront(int value);
    void pushBack(int value);
    void insertAt(int index, int value);
    void deleteAt(int index);

    void printList();

    int findValue(int value);
    int at(int index);
    int getSize();
};
#endif