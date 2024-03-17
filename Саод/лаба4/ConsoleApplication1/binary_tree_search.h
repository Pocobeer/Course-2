#pragma once
#include <queue>

class Node_bin {
public:
    int key;
    Node_bin* left;
    Node_bin* right;

    Node_bin(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node_bin* root;

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        Node_bin* newNode = new Node_bin(key);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node_bin* current = root;
        while (true) {
            if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else if (key > current->key) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    bool binary_tree_search(int key) {
        if (root == nullptr) {
            return false;
        }

        Node_bin* current = root;
        while (current != nullptr) {
            if (key == current->key) {
                return true;
            }
            else if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return false;
    }
};