#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include <iostream>
#include <memory>
#include <initializer_list>

class BinarySearchTree {
private:

    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node() = default;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;
    int size;

    void insert(std::unique_ptr<Node>& node, int value);
    void inorder(const std::unique_ptr<Node>& node) const;
    void preorder(const std::unique_ptr<Node>& node) const;
    void postorder(const std::unique_ptr<Node>& node) const;
    bool search(const std::unique_ptr<Node>& node, int value) const;

public:
    BinarySearchTree();
    BinarySearchTree(std::initializer_list<int> elements);

    void insertElement(int value);
    void displayInorder() const;
    void displayPreorder() const;
    void displayPostorder() const;
    int getSize() const;
    bool find(int value) const;
};

#endif