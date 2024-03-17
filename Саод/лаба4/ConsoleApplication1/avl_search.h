#include <stack>

struct Node_avl {
    int key;
    Node_avl* left;
    Node_avl* right;
};

// Функция поиска в AVL-дереве
Node_avl* search(Node_avl* root, int key) {
    std::stack<Node_avl*> s;
    Node_avl* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        if (current->key == key) {
            return current;
        }

        current = current->right;
    }

    return nullptr; // Если ключ не найден
}

// Функция вставки узла в AVL-дерево
Node_avl* insert(Node_avl* root, int key) {
    if (root == nullptr) {
        return new Node_avl{ key, nullptr, nullptr };
    }

    Node_avl* current = root;
    Node_avl* parent = nullptr;

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
        parent->left = new Node_avl{ key, nullptr, nullptr };
    }
    else {
        parent->right = new Node_avl{ key, nullptr, nullptr };
    }

    return root;
}
