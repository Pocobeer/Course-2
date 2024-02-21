#pragma once

// ��������� ���� AVL ������
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    // ����������� ����
    Node(int value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// ������� ��� ���������� ������ ����
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// ������� ��� ���������� ������� ���� (������� ����� �����������)
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// ������� ��� �������� ����� ������
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // �������
    x->right = y;
    y->left = T;

    // ���������� �����
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// ������� ��� �������� ����� �����
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // �������
    y->left = x;
    x->right = T;

    // ���������� �����
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// ������� ��� ������� ���� � AVL ������
Node* insert(Node* node, int value) {
    // ��� 1: ������� ������� ���� � BST
    if (node == nullptr) {
        return new Node(value);
    }

    // ��� 2: ������� ������ �����
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

        // ��� 3: ���������� ������ ����
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // ��� 4: ��������� ������� ���� � �������� �� ��������� �������
        int balance = getBalance(node);

        // ���� ���� ���������������, ���� ������ ������ ��� ���������

        // ����-���� ������
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // �����-����� ������
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // ����-����� ������
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // �����-���� ������
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}
// ����� � AVL ������
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