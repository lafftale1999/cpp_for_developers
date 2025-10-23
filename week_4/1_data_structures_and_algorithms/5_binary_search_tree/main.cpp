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

    void preorder(const std::unique_ptr<Node>& node) const {
        if(!node) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(const std::unique_ptr<Node>& node) const {
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    bool search(const std::unique_ptr<Node>& node, int value) const {
        if (!node) return false;
        if (node->data == value) return true;

        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
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

    void displayPreorder() const {
        preorder(root);
    }

    void displayPostorder() const {
        postorder(root);
    }

    int getSize() const {
        return size;
    }

    bool find(int value) const {
        return search(root, value);
    }
};

int main(void) {
    BinarySearchTree bst = {3, 9, 23, 91, 2, 34, 8, 2, 5, 17, 24, 9, 1, 54, 76};

    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();
    
    int numbers[] = {9, 21, 5, 76, 4};
    for(auto& n : numbers) {
        if (bst.find(n)) {
            std::cout << n << " was found in the bst\n";
        } else {
            std:: cout << n << " was not found in the bst\n";
        }
    }

    bst.insertElement(21);

    if (bst.find(21)) std::cout << "21 was found in the bst!\n";
    std::cout << bst.getSize() << std::endl;
    return 0;
}