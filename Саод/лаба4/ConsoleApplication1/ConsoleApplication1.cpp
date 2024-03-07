#include<iostream>
#include<vector>
#include "fibonacci.h"
#include "search.h"
#include "binary_search.h"
#include "interpolation_search.h"
//#include "binary_tree_search.h"
#include "avl_search.h"
//
// #include "Dig_search.h"
#include<algorithm>
using namespace std;


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
	
	
	const int size = 13000;
	int arr[size];
	int target = 156;
	int index;
	//vector<int> d_s;
	Node* binaryroot = nullptr;
	for (int i = 1; i < size; i++) {
		arr[i] = i*2;
		binaryroot = insert(binaryroot, i);
		//d_s.push_back(i * 2);
	}
	Node* avlroot = nullptr;
	//Dig_search d_search(d_s);
	for (int i = 2; i < size; i +=2) {
		avlroot = insert(avlroot,i);
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
	if (searchBST(binaryroot, target)) cout << "Element " << target << " was found in position " << index << endl;
	else cout << "Element wasn't found" << endl;
	cout << "\nAvl tree search" << endl;
	if (searchAVL(avlroot, target)) cout << "Element " << target << " was found in position " << index << endl;
	else cout << "Element wasn't found" << endl;
	cout << "\nDigital search" << endl;
	//auto d_index = d_search.solve(target);
	//if (d_index == target) cout << "Element " << target << " was found in position " << index << endl;
	//if (d_index == -1) cout << "Element wasn't found" << endl;
	cout << "\nHash search" << endl;
	hash_table ht;
	ht.insert(10, 20);
	ht.insert(14, 38);
	cout << "Index for key 10: " << ht.search(10) << endl;
	cout << "Index for key 8: " << ht.search(8) << endl;
}