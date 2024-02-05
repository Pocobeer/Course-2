#pragma once
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