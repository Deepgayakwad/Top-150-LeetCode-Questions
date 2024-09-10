#include <map> // Include necessary headers

class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    std::map<int, Node*> mpp; // Corrected to use std::map
    int capacity;
    Node *head, *tail;

private:
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* currentAfterHead = head->next;
        head->next = node;
        node->next = currentAfterHead;
        node->prev = head;
        currentAfterHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        
        head = new Node(0, 0); // Initialize head
        tail = new Node(0, 0); // Initialize tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1; // Check if key exists

        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return; // Handle zero capacity case

        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node; // Properly delete node to avoid memory leak
            }

            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

