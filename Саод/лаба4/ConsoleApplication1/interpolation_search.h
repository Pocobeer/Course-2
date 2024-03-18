#pragma once
bool interpolation_saerch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right && target >= arr[left] && target <= arr[right]) {
		int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
		if (arr[pos] == target) {
			return true;
		}
		else if (arr[pos] < target) {
			left = pos + 1;
		}
		else {
			right = pos - 1;
		}
	}
	return false;
}