#pragma once

// Структура узла AVL дерева
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    // Конструктор узла
    Node(int value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Функция для вычисления высоты узла
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Функция для вычисления баланса узла (разница высот поддеревьев)
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Функция для вращения узлов вправо
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // Поворот
    x->right = y;
    y->left = T;

    // Обновление высот
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Функция для вращения узлов влево
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // Поворот
    y->left = x;
    x->right = T;

    // Обновление высот
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Функция для вставки узла в AVL дерево
Node* insert(Node* node, int value) {
    // Шаг 1: Обычная вставка узла в BST
    if (node == nullptr) {
        return new Node(value);
    }

    // Шаг 2: Вставка четных чисел
    if (value % 2 == 0) {
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        else {
            return node;
        }

        // Шаг 3: Обновление высоты узла
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Шаг 4: Получение баланса узла и проверка на нарушение баланса
        int balance = getBalance(node);

        // Если узел несбалансирован, есть четыре случая для поворотов

        // Лево-Лево случай
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // Право-Право случай
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // Лево-Право случай
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Право-Лево случай
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}
// Поиск в AVL дереве
bool avl_search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return avl_search(root->left, value);
    }
    else {
        return avl_search(root->right, value);
    }
}