#include<iostream>
#include<set>
#include "fibonacci.h"
#include "search.h"
#include "binary_search.h"
#include "interpolation_search.h"
//#include "binary_tree_search.h"
//#include "avl_search.h"
#include<algorithm>
using namespace std;
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
	~Node() {
		delete left;
		delete right;
	}
};

// Вставка узла в бинарное дерево
Node* binaryInsert(Node* node, int value) {
	if (node == nullptr)
		return new Node(value);

	if (value < node->data)
		node->left = binaryInsert(node->left, value);
	else if (value > node->data)
		node->right = binaryInsert(node->right, value);

	return node;
}

// Поиск в бинарном дереве
bool binary_search(Node* root, int value) {
	if (root == nullptr)
		return false;

	if (root->data == value)
		return true;
	else if (value < root->data)
		return binary_search(root->left, value);
	else
		return binary_search(root->right, value);
}

// Вставка узла в AVL дерево
Node* avl_insert(Node* node, int value) {
	if (node == nullptr)
		return new Node(value);

	if (value < node->data)
		node->left = avl_insert(node->left, value);
	else if (value > node->data)
		node->right = avl_insert(node->right, value);

	return node;
}

// Функция для вычисления высоты узла
int getHeight(Node* node) {
	if (node == nullptr)
		return 0;
	return node->height;
}

// Поиск в AVL дереве
bool avl_search(Node* root, int value) {
	if (root == nullptr)
		return false;

	if (root->data == value)
		return true;
	else if (value < root->data)
		return avl_search(root->left, value);
	else
		return avl_search(root->right, value);
}
int hash_function(int key, int array_size) {
	return key & array_size;
}
int digital_search(int arr[], int size1, int key) {
	int index = hash_function(key, size1);
	if (index >= 0 && index < size1 && arr[index] == key) {
		return index;
	}
	return -1;
}
class hash_table {
	static const int capasity = 10;
	int table[capasity][2];
	int hash_function_2(int key) {
		return key % capasity;
	}
public:
	hash_table() {
		for (int i = 0; i < capasity; i++) {
			table[i][0] = -1;
		}
	}
	void insert(int key, int value) {
		int index = hash_function_2(key);
		while (table[index][0] != -1 && table[index][0] != key) {
			index = (index + 1) % capasity;
		}
		table[index][0] = key;
		table[index][1] = value;
	}
	int search(int key) {
		int index = hash_function_2(key);
		int o_index = index;
		while (table[index][0] != 1) {
			if (table[index][0] == key) {
				return table[index][1];
			}
			index = (index + 1) % capasity;
			if (index == o_index) {
				break;
			}
		}
		return -1;
	}
};
int main() {
	
	
	const int size = 6300;
	int arr[size];
	int target = 10;
	int index;
	//set<int> avlTree;
	//Node* binaryroot = nullptr;
	for (int i = 1; i < size; i++) {
		arr[i] = i*2;
		//binaryroot = binaryInsert(binaryroot, i);
	}
	Node* avlroot = nullptr;
	for (int i = 2; i < size; i +=2) {
		avlroot = avl_insert(avlroot,i);
	}
	cout << "Sequental search" << endl;
	index = search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "\nUsual binary search" << endl;
	index = binary_search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "\nFibonacci search" << endl;
	int result = fibonacci_search(target);
	if (result == -1) cout << "Element need to be more than 0" << endl;
	else cout << "Number in Fibonacci sequence: " << result << endl;
	cout << "\nInterpolation search" << endl;
	index = interpolation_saerch(arr, size, target);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "\nBinary tree search" << endl;
	int size1 = sizeof(arr) / sizeof(arr[0]);
	//if (binary_search(binaryroot, target)) cout << "Element " << target << " was found in position " << index << endl;
	//else cout << "Element wasn't found" << endl;
	cout << "\nAvl tree search" << endl;
	if (avl_search(avlroot, target)) cout << "Element " << target << " was found in position " << index << endl;
	else cout << "Element wasn't found" << endl;
	cout << "\nDigital search" << endl;
	index = digital_search(arr, size1, target);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "\nHash search" << endl;
	hash_table ht;
	ht.insert(10, 20);
	ht.insert(14, 38);
	cout << "Index for key 10: " << ht.search(10) << endl;
	cout << "Index for key 8: " << ht.search(8) << endl;
}