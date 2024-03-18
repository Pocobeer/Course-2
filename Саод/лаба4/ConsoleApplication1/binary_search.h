#pragma once
bool binary_search(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return true;
		}
		else if (arr[mid] <= target) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return false;
}