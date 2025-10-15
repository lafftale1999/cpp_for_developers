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
    LinkedList() : head(nullptr), size(0) {}
    LinkedList(std::initializer_list<int> elements)
    : head(nullptr), size(0) {
        for (auto& e : elements) {
            pushBack(e);
        }
    }

    void pushFront(int value) {
        auto newNode = std::make_unique<Node>(value); // create a new node

        newNode->next = std::move(head); // set our new node to point to our current head
        head = std::move(newNode); // change so that head is now pointing to our new node
        size++; // increase size
    }

    void pushBack(int value) {
        auto newNode = std::make_unique<Node>(value); // create a new node

        if (!head) { // if it is the first node - point head to it
            head = std::move(newNode);
        } else {
            Node* current = head.get(); // get the first node
            
            while(current->next) { // while the current node has a pointer to the next
                current = current->next.get(); // reassign the node to the next one
            }

            // When we are out of the while loop, we know that we have reached the end
            // of our linked list and adds our new node there.
            current->next = std::move(newNode);
        }

        size++;
    }

    void insertAt(int index, int value) {
        
        // check that the index is valid for our list
        if (index < 0 || index > size) {
            throw std::out_of_range("Trying to access element out of range");
        }

        // check if it should be added to front or back
        if (index == 0) {
            pushFront(value);
            return; 
        } else if (index == size) {
            pushBack(value);
            return;
        }

        // Find the node before our index
        Node* before = head.get();
        for (int i = 1; i < index; i++) { // why start at 1? So we iterate index -1 times to end up on the node before
            before = before->next.get();
        }

        // add the new node
        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(before->next); // point our node the the one after
        before->next = std::move(newNode); // point the node before to the new one
        size++;
    }

    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Trying to access element out of range");
        }

        if (index == 0) {
            head = std::move(head->next);
            size--;
            return;
        }

        // Find the node before our index
        Node* before = head.get();
        for (int i = 1; i < index; i++) {
            before = before->next.get();
        }

        auto nodeToRemove = std::move(before->next); // nodeToRemove owns "itself"
        before->next = std::move(nodeToRemove->next); // rearrange pointer to skip the node to remove
        size--;
    } // when nodeToRemove goes out of scope - delete is called implicitly


    void printList() {
        Node* current = head.get();

        while(current) {
            std::cout << current->data << std::endl;
            current = current->next.get();
        }
    }

    int findValue(int value) {
        
        Node* current = head.get();

        for (int i = 0; i < size; i++) {
            if (current->data == value) return i;
            current = current->next.get();
        }

        return -1;
    }

    int at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Trying to access outside of range");
        }

        Node* current = head.get();

        for (int i = 0; i < size; i++) {
            if (i == index) return current->data;
            current = current->next.get();
        }

        throw std::runtime_error("Reached end of list without finding element");
    }

    int getSize() {return size;}
};

int main() {
    LinkedList list = {29, 32, 11, 92, 38, 29};
    
    std::cout << "---- FIRST PRINT --------\n";
    list.printList();
    std::cout << "-------------------------\n\n";
    
    std::cout << "at(1) before insert: " << list.at(1) << std::endl;
    list.insertAt(1, 111);
    std::cout << "at(1) after insert: " << list.at(1) << std::endl;

    list.pushFront(21);
    list.pushBack(99);
    
    std::cout << "---- SECOND PRINT --------\n";
    list.printList();
    std::cout << "-------------------------\n\n";
    
    std::cout << "92 found at index: " << list.findValue(92) << std::endl;
}