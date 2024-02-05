#include<iostream>
#include<set>
#include "fibonacci.h"
#include "search.h"
#include "binary_search.h"
#include "interpolation_search.h"
#include "binary_tree_search.h"
#include "avl_search.h"
using namespace std;
bool avl_search(set<int>& avlTree, int value) {
	set<int>::iterator it = avlTree.find(value);
	return it != avlTree.end();
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
	const int size = 100000;
	int arr[size];
	int target = 106;
	int index;
	set<int> avlTree;
	for (int i = 0; i < size; i++) {
		arr[i] = (i+1)*2;
	}
	for (int i = 0; i < size; i++) {
		avlTree.insert(arr[i]);
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
	index = binary_tree_search(arr, size1, target, 1);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "\nAvl binary tree search" << endl;
		//size1 = sizeof(arr) / sizeof(arr[0]);
		//cout << size1 << endl;
	if (avl_search(avlTree, target)) cout << "Element " << target << " was found in position " << index << endl;
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