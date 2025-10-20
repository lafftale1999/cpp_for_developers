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

    void insert(std::unique_ptr<Node>& node, int value) {
        if (!node) {
            node = std::make_unique<Node>(value);
            size++;
            return;
        }

        if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }

        // ignore duplicates
    }

    void inorder(const std::unique_ptr<Node>& node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr), size(0) {}
    BinarySearchTree(std::initializer_list<int> elements)
    : root(nullptr), size(0) {
        for (auto& element: elements) {
            insertElement(element);
        }
    }

    void insertElement(int value) {
        insert(root, value);
    }

    void displayInorder() const {
        inorder(root);
    }

    int getSize() const {
        return size;
    }
};

int main(void) {
    BinarySearchTree bst = {3, 9, 23, 91, 2, 34, 8, 2, 5, 17, 24, 9, 1, 54, 76};

    bst.displayInorder();
    std::cout << bst.getSize() << std::endl;
    return 0;
}