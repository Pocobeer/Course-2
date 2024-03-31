#pragma once

#include "all_includes.h"


class tre_search : public BASIC_CLASS {
public:

    tre_search(vector<int>& VEC) : root(nullptr) {
        insert(VEC[VEC.size() / 2]);
        for (int i = 1; i < VEC.size() / 2; i++) {
            insert(VEC[VEC.size()/2 - 1 - i]);
            insert(VEC[VEC.size()/2 - 1 + i]);
        }
    }

    void change_isk(int isk_) override {
        ISKOMOE = isk_;
    }
    string get_name() override {
        return NAME;
    }
    void insert(int key) {
        root = insertRec(root, key);
    }

    int solve() override {
        Node* RES = searchRec(root, ISKOMOE);
        if (RES == nullptr) {
            return -1;
        }
        return RES->key;
    }
    int solve(int isk_) override {
        change_isk(isk_);
        return solve();
    }
    int get_iter() {
        int temp_i = ITER_COUNT;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& VEC) {
        root = nullptr;
        int VEC_S = VEC.size() - 1;
        int w = 0, e = VEC_S / 2;
        for (int q = VEC_S / 4; q > 0; q--) {
            w = VEC_S - q;
            insert(VEC[q]);
            insert(VEC[w]);
            insert(VEC[e + q]);
            insert(VEC[e - q]);
        }
    }
private:
    class Node {
    public:
        int key;
        Node* left;
        Node* right;

        Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int ISKOMOE = -1;
    string NAME = "Поиск в обычном дереве";
    int ITER_COUNT = 0;

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (key < parent->key) {
            parent->left = new Node(key);
        }
        else {
            parent->right = new Node(key);
        }

        return root;
    }

    Node* searchRec(Node* root, int key) {
        while (root != nullptr && root->key != key) {
            if (key < root->key) {
                root = root->left;
                ITER_COUNT++;
            }
            else {
                root = root->right;
                ITER_COUNT++;
            }
        }

        return root;
    }
};