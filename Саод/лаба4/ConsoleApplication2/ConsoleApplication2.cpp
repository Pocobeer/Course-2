#include <iostream>
#include <algorithm>
using namespace std;

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
int main() {


	const int size = 1000;
	int arr[size];
	int target = 10;
	int index;
	for (int i = 0; i < size; i ++) {
		arr[i] = i*2;
		cout << arr[i] << " ";
	}
	cout << "\nUsual binary search" << endl;
	index = binary_search(arr, size, target);
	cout << index << endl;
	if (index != -1) std::cout << "Element " << target << " was found in position " << index << std::endl;
	if (index == -1) std::cout << "Element wasn't found" << std::endl;
}