#pragma once
#include <unordered_map>
#include <sstream>

class DSTNode {
public:
    bool isEndOfNumber;
    std::unordered_map<char, DSTNode*> children;

    DSTNode() {
        isEndOfNumber = false;
    }
};

class DigitalSearchTree {
private:
    DSTNode* root;

    void insertNumber(DSTNode* node, int number) {
        std::stringstream ss;
        ss << number;
        std::string numberString = ss.str();

        for (char c : numberString) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new DSTNode();
            }
            node = node->children[c];
        }
        node->isEndOfNumber = true;
    }

    bool searchNumber(DSTNode* node, int number) {
        std::stringstream ss;
        ss << number;
        std::string numberString = ss.str();

        for (char c : numberString) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node != nullptr && node->isEndOfNumber;
    }

public:
    DigitalSearchTree() {
        root = new DSTNode();
    }

    void insert(int number) {
        insertNumber(root, number);
    }

    bool search(int number) {
        return searchNumber(root, number);
    }
};
