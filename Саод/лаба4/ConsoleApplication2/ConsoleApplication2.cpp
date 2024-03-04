#include <iostream>
//#include <stack>

// Структура узла для деревьев
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Функция для поиска элемента в обычном бинарном дереве поиска
bool searchBST(Node* root, int target) {
    while (root != nullptr) {
        if (root->key == target) {
            return true; // Нашли элемент
        }
        else if (target < root->key) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return false; // Элемент не найден
}

// Функция для поиска элемента в AVL-дереве
bool searchAVL(Node* root, int target) {
    while (root != nullptr) {
        if (root->key == target) {
            return true; // Нашли элемент
        }
        else if (target < root->key) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return false; // Элемент не найден
}

// Функция для вставки элемента в дерево
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

int main() {
    setlocale(LC_ALL, "ru");
    const int size = 1000;
    // Пример создания и заполнения обычного бинарного дерева поиска
    Node* rootBST = nullptr;
    for (int i = 0; i < size; i++) {
        rootBST = insert(rootBST, i*2);
    }

    // Пример создания и заполнения AVL-дерева
    Node* rootAVL = new Node(size);
    for (int i = 0; i < size; i ++) {
        rootAVL = insert(rootAVL, i*2);
    }

    int target = 15;
    if (searchBST(rootBST, target)) {
        std::cout << "Элемент найден в обычном бинарном дереве поиска!\n";
    }
    else {
        std::cout << "Элемент не найден в обычном бинарном дереве поиска.\n";
    }

    if (searchAVL(rootAVL, target)) {
        std::cout << "Элемент найден в AVL-дереве!\n";
    }
    else {
        std::cout << "Элемент не найден в AVL-дереве.\n";
    }

    // Освобождаем память после использования
    // Допиши свой код

    return 0;
}
