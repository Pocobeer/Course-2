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
    Node* newNode = new Node(key);

    if (root == nullptr) {
        return newNode;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current) {
        parent = current;

        if (key < current->key) {
            current = current->left;
            if (current == nullptr) {
                parent->left = newNode;
                return root;
            }
        }
        else if (key > current->key) {
            current = current->right;
            if (current == nullptr) {
                parent->right = newNode;
                return root;
            }
        }
        else {
            // Если ключ уже существует, то просто освобождаем память для нового узла и возвращаем исходное дерево
            delete newNode; // Освобождаем память
            return root;
        }
    }

    // Недостижимый код, но для корректности можно добавить
    return root;
}


int main() {
    setlocale(LC_ALL, "ru");
    const int size = 10000;
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

    int target = 16540;
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
