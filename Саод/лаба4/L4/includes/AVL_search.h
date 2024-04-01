#pragma once

#include "all_includes.h"

class AVL_search : public BASIC_CLASS {
private:
    vector<int> data;
    int iterations = 0;
    int temp_iter = 0;

    struct Node {
        int data;
        int height;
        Node* left;
        Node* right;
        Node* Father;  // Добавлено поле для указателя на отца

        Node(int value) : data(value), height(1), left(nullptr), right(nullptr), Father(nullptr) {}
    };

    Node* root;

public:
    AVL_search(vector<int> &data) : data(data), iterations(0), root(nullptr) {
        for (auto& a : data) {
            insert(a);
        }
    }

    string get_name() override {
        return "AVL-поиск";
    }

    void change_isk(int isk) override {
        iterations = isk;
    }

    void updateHeight(Node* node) {
        int leftHeight = (node->left == nullptr) ? 0 : node->left->height;
        int rightHeight = (node->right == nullptr) ? 0 : node->right->height;
        node->height = max(leftHeight, rightHeight) + 1;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = (node->left == nullptr) ? 0 : node->left->height;
        int rightHeight = (node->right == nullptr) ? 0 : node->right->height;
        return leftHeight - rightHeight;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->Father = x;
        }
        y->Father = x->Father;
        if (x->Father == nullptr) {
            root = y;
        }
        else if (x == x->Father->left) {
            x->Father->left = y;
        }
        else {
            x->Father->right = y;
        }
        y->left = x;
        x->Father = y;
        updateHeight(x);
        updateHeight(y);
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->Father = y;
        }
        x->Father = y->Father;
        if (y->Father == nullptr) {
            root = x;
        }
        else if (y == y->Father->left) {
            y->Father->left = x;
        }
        else {
            y->Father->right = x;
        }
        x->right = y;
        y->Father = x;
        updateHeight(y);
        updateHeight(x);
    }

    void rebalance(Node* node) {
        updateHeight(node);
        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (getBalanceFactor(node->left) < 0) {
                leftRotate(node->left);
            }
            rightRotate(node);
        }
        else if (balance < -1) {
            if (getBalanceFactor(node->right) > 0) {
                rightRotate(node->right);
            }
            leftRotate(node);
        }
    }

    void insert(int value, Node* node) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
                node->left->Father = node;  // Установка указателя на отца
            }
            else {
                insert(value, node->left);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(value);
                node->right->Father = node;  // Установка указателя на отца
            }
            else {
                insert(value, node->right);
            }
        }

        rebalance(node);
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insert(value, root);
        }
    }

    bool search(int key, Node* node) {
        if (node == nullptr) {
            iterations++;
            return false;
        }
        else if (key == node->data) {
            iterations++;
            return true;
        }
        else if (key < node->data) {
            iterations++;
            return search(key, node->left);
        }
        else {
            iterations++;
            return search(key, node->right);
        }
    }

    int search(int key) {
        auto temp_ = search(key, root);
        if (temp_ == false) {
            return -1;
        }
        else {
            return key;
        }
    }

    int solve() override {
        return search(root->data);
    }

    int solve(int key) override {
        return search(key);
    }

    int get_iter() override {
        temp_iter = iterations;
        iterations = 0;
        return temp_iter;
    }

    void restruct(vector<int>& __a) override {
        data = __a;
    }
};