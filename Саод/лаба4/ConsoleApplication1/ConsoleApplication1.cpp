#include<iostream>
#include<vector>
#include<stack>
#include<random>
#include<ctime>
#include "fibonacci.h"
#include "search.h"
#include "binary_search.h"
#include "interpolation_search.h"
#include "hash_search.h"
#include "binary_tree_search.h"
#include "avl_search.h"
#include "dig_search.h"
#include<algorithm>
using namespace std;

int main() {
	mt19937 gen(time(0));
	
	cout << "n = 20000" << endl;
	cout << "Search method          " << "UP       " << "BP      " << endl;
	uniform_int_distribution<int> dist(1, 5000);
	DigitalSearchTree trie;
	BST tree;
	const int size = 20000;
	int arr[size];
	int target[size];
	int index;
	vector<int> h_s;
	Node_avl* root = nullptr;
	int up_1 = 0, bp_1 = 0, up_2 = 0, bp_2 = 0, up_3 = 0, bp_3 = 0;
	int up_4 = 0, bp_4 = 0, up_5 = 0, bp_5 = 0, up_6 = 0, bp_6 = 0;
	int up_7 = 0, bp_7 = 0, up_8 = 0, bp_8 = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = i * 2;
		tree.insert(i * 2);
		trie.insert(i * 2);
		h_s.push_back(i * 2);
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	//Dig_search d_search(d_s);
	for (int dat : arr) {
		root = insert(root, dat);
	}
	for (int num : h_s) {
		insertIntoHashTable(num);
	}
	for (int j = 0; j < size; j++){
		target[j] = dist(gen);
		//target[j] = j;
	}
	for (int a = 0; a < size; a++) {
		index = search(arr, size, target[a]);
		if (index ) up_1 += 1;
		else bp_1 += 1;
		index = binary_search(arr, size, target[a]);
		if (index) up_2 += 1;
		else bp_2 += 1;
		index = fibMonaccianSearch(arr, target[a], n);
		if (index) up_3 += 1;
		else bp_3 += 1;
		index = interpolation_saerch(arr, size, target[a]);
		if (index) up_4 += 1;
		else bp_4 += 1;
		if (tree.binary_tree_search(target[a])) up_5 += 1;
		else bp_5+=1;
		Node_avl* result_avl = search(root, target[a]);
		if (result_avl != nullptr) up_6 += 1;
		else bp_6 += 1;
		if (trie.search(target[a])) up_7 += 1;
		else bp_7 += 1;
		if (searchInHashTable(target[a])) up_8 += 1;
		else bp_8 += 1;
	}
	cout << "Sequental search       " << up_1 << "     " << bp_1 << endl;
	cout << "Usual binary search    " << up_2 << "     " << bp_2 << endl;
	cout << "Fibonacci search       " << up_3 << "     " << bp_3 << endl;
	cout << "Interpolation search   " << up_4 << "     " << bp_4 << endl;
	cout << "Binary tree search     " << up_5 << "     " << bp_5 << endl;
	cout << "Avl tree search        " << up_6 << "     " << bp_6 << endl;
	cout << "Digital search         " << up_7 << "     " << bp_7 << endl;
	cout << "Hash search            " << up_8 << "     " << bp_8 << endl;
	cout << "n = 40000" << endl;
	cout << "Search method          " << "UP       " << "BP      " << endl;
	const int size = 40000;
	for (int a = 0; a < size; a++) {
		index = search(arr, size, target[a]);
		if (index) up_1 += 1;
		else bp_1 += 1;
		index = binary_search(arr, size, target[a]);
		if (index) up_2 += 1;
		else bp_2 += 1;
		index = fibMonaccianSearch(arr, target[a], n);
		if (index) up_3 += 1;
		else bp_3 += 1;
		index = interpolation_saerch(arr, size, target[a]);
		if (index) up_4 += 1;
		else bp_4 += 1;
		if (tree.binary_tree_search(target[a])) up_5 += 1;
		else bp_5 += 1;
		Node_avl* result_avl = search(root, target[a]);
		if (result_avl != nullptr) up_6 += 1;
		else bp_6 += 1;
		if (trie.search(target[a])) up_7 += 1;
		else bp_7 += 1;
		if (searchInHashTable(target[a])) up_8 += 1;
		else bp_8 += 1;
	}
	cout << "Sequental search       " << up_1 << "     " << bp_1 << endl;
	cout << "Usual binary search    " << up_2 << "     " << bp_2 << endl;
	cout << "Fibonacci search       " << up_3 << "     " << bp_3 << endl;
	cout << "Interpolation search   " << up_4 << "     " << bp_4 << endl;
	cout << "Binary tree search     " << up_5 << "     " << bp_5 << endl;
	cout << "Avl tree search        " << up_6 << "     " << bp_6 << endl;
	cout << "Digital search         " << up_7 << "     " << bp_7 << endl;
	cout << "Hash search            " << up_8 << "     " << bp_8 << endl;
	/*cout << "Sequental search" << endl;
	index = search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "\nUsual binary search" << endl;
	index = binary_search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "\nFibonacci search" << endl;
	int result = fibMonaccianSearch(arr, target, n);
	if (result >= 0) cout << target << "Found " << endl;
	else cout << target << " isn't present in the array" << endl;
	cout << "\nInterpolation search" << endl;
	index = interpolation_saerch(arr, size, target);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "\nBinary tree search" << endl;
	int size1 = sizeof(arr) / sizeof(arr[0]);
	if (tree.binary_tree_search(target)) cout << "Element " << target << " was found in position " << index << endl;
	else cout << "Element wasn't found" << endl;
	cout << "\nAvl tree search" << endl;
	Node_avl* result_avl = search(root, target);
	if (result_avl != nullptr) {
		std::cout << "Found" << std::endl;
	}
	else {
		std::cout << "Wasn't found" << std::endl;
	}
	cout << "\nDigital search" << endl;
	if (trie.search(target)) {
		std::cout << "Element " << target << " was found." << std::endl;
	}
	else {
		std::cout << "Element " << target << " wasn't found." << std::endl;
	}
	cout << "\nHash search" << endl;
	if (searchInHashTable(target)) {
		std::cout << "element " << target << " was found." << std::endl;
	}
	else {
		std::cout << "element " << target << " wasn't found." << std::endl;
	}*/
}