#include<iostream>
using namespace std;
int search (int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}
int binary_search(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] <= target) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return -1;
}
int fibonacci_search(int target) {
	if (target <= 0) {
		return -1;
	}
	else if (target == 1 || target == 2) {
		return 1;
	}
	else {
		int *fib = new int[target + 1];
		fib[0] = 0;
		fib[1] = 1;
		for (int i = 2; i <= target; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		int result = fib[target];
		delete[] fib;
		return result;
	}
}
int interpolation_saerch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right && target >= arr[left] && target <= arr[right]) {
		int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
		if (arr[pos] == target) {
			return pos;
		}
		else if (arr[pos] < target) {
			left = pos + 1;
		}
		else {
			right = pos - 1;
		}
	}
	return -1;
} 
int binary_tree_search(int arr[], int size1, int target, int pos) {
	if (pos >= size1) {
		return -1; 
	}
	if (arr[pos] == target) {
		return pos;
	}
	int leftResult = binary_tree_search(arr, size1, target, 2 * pos);
	if (leftResult != -1) {
		return leftResult;
	}

	int rightResult = binary_tree_search(arr, size1, target, 2 * pos + 1);
	return rightResult;
}
int avl_tree_search(int arr[], int size1, int target, int pos) {
	if (pos >= size1 || arr[pos] == 0) {
		return -1;
	}
	if (arr[pos] == target) {
		return pos;
	}
	else if(arr[pos] < target){
		return avl_tree_search(arr, size1, target, 2*pos+2);
	}
	else {
		return avl_tree_search(arr, size1, target, 2*pos+1);
	}
}
int hash_function(int key, int array_size) {
	return key & array_size;
}
int digital_search(int arr[], int array_size, int key) {
	int index = hash_function(key, array_size);
	if (index >= 0 && index < array_size && arr[index] == key) {
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
	const int size = 50;
	int arr[size];
	int target = 6;
	int index;
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
	cout << "Sequental search" << endl;
	index = search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "Usual binary search" << endl;
	index = binary_search(arr, size, target);
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
	cout << "Fibonacci search" << endl;
	int result = fibonacci_search(target);
	if (result == -1) cout << "Element need to be more than 0" << endl;
	else cout << "Number in Fibonacci sequence: " << result << endl;
	cout << "Interpolation search" << endl;
	index = interpolation_saerch(arr, size, target);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "Binary tree search" << endl;
	int size1 = sizeof(arr) / sizeof(arr[0]);
	index = binary_tree_search(arr, size1, target, 1);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "Avl binary tree search" << endl;\
	size1 = sizeof(arr) / sizeof(arr[0]);
	index = avl_tree_search(arr, size1, target, 0);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "Digital search" << endl;
	index = digital_search(arr, size1, target);
	if (index != -1) cout << "Element " << target << " was found in position " << index << endl;
	if (index == -1) cout << "Element wasn't found" << endl;
	cout << "Hash search" << endl;
	hash_table ht;
	ht.insert(10, 20);
	ht.insert(14, 38);
	cout << "Index for key 10: " << ht.search(10) << endl;
	cout << "Index for key 8: " << ht.search(8) << endl;
}