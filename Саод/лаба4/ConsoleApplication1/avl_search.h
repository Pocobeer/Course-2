#pragma once

// ��������� ���� AVL ������
// ��������� ���� ��� ��������
struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// ������� ��� ������ �������� � ������� �������� ������ ������
bool searchBST(Node* root, int target) {
	while (root != nullptr) {
		if (root->key == target) {
			return true; // ����� �������
		}
		else if (target < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return false; // ������� �� ������
}

// ������� ��� ������ �������� � AVL-������
bool searchAVL(Node* root, int target) {
	while (root != nullptr) {
		if (root->key == target) {
			return true; // ����� �������
		}
		else if (target < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return false; // ������� �� ������
}

// ������� ��� ������� �������� � ������
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
			// ���� ���� ��� ����������, �� ������ ����������� ������ ��� ������ ���� � ���������� �������� ������
			delete newNode; // ����������� ������
			return root;
		}
	}

	return root;
}
