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

public:
    BinarySearchTree() : root(nullptr), size(0) {}
    BinarySearchTree(std::initializer_list<int> elements)
    : root(nullptr), size(0) {

    }

    void insertElement(int value) {
        if (!root) {
            root = std::make_unique<Node>(value);
        } else {
            
        }
    }
};