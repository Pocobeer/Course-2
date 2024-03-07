#pragma once

// Структура узла AVL дерева
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

	return root;
}
