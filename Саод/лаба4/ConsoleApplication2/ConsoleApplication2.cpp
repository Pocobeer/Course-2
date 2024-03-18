#include <iostream>
#include <stack>

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Функция поиска в AVL-дереве
Node* search(Node* root, int key) {
    std::stack<Node*> s;
    Node* current = root;

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
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node{ key, nullptr, nullptr };
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new Node{ key, nullptr, nullptr };
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new Node{ key, nullptr, nullptr };
                break;
            }
            current = current->right;
        }
    }

    return root;
}

int main() {
    // Создание и заполнение AVL-дерева с помощью цикла
    Node* root = nullptr;
    const int size = 200000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
    for (int key : arr) {
        root = insert(root, key);
    }

    int keyToFind = 156800;
    Node* result = search(root, keyToFind);

    if (result != nullptr) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Wasn't found" << std::endl;
    }

    return 0;
}
