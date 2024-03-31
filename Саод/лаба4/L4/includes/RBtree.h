#pragma once

#include "all_includes.h"

class RBT_search : public BASIC_CLASS {
public:
    RBT_search(vector<int>& a) : root(nullptr){
        for (const auto& a_ : a) {
            insert(a_);
        }
    }
    RBT_search(vector<int>& a, int isk_) : root(nullptr) {
        ISKOMOE = isk_;
        for (const auto& a_ : a) {
            insert(a_);
        }
    }
    string get_name() override {
        return NAME;
    }
    void change_isk(int isk_) override {
        ISKOMOE = isk_;
    }
    void insert(int key) {
        Node* z = new Node(key);
        insert(z);
    }

    int solve() override {
        Node* result = searchRec(root, ISKOMOE);
        if (result != nullptr) {
            return result->key;
        }
        return -1;
    }
    int solve(int isk_) {
        change_isk(isk_);
        return solve();
    }
    int get_iter() {
        int temp_i = ITER_COUNT;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& a) {

    }
private:
    int ISKOMOE = -1;
    string NAME = "Поиск в RB дереве";
    int ITER_COUNT = 0;
    enum Color { RED, BLACK };

    class Node {
    public:
        int key;
        Color color;
        Node* parent;
        Node* left;
        Node* right;

        Node(int _key, Color _color = RED, Node* _parent = nullptr, Node* _left = nullptr, Node* _right = nullptr) : key(_key), color(_color), parent(_parent), left(_left), right(_right) {}
    };

    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void insert(Node* z) {
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        z->color = RED;
        fixInsert(z);
    }

    Node* searchRec(Node* node, int key) {
        ITER_COUNT++;
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return searchRec(node->left, key);
        }
        else {
            return searchRec(node->right, key);
        }
    }
};