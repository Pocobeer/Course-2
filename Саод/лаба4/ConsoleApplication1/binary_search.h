#pragma once
int up_2 = 0, bp_2 = 0;
std::pair<bool, int> binary_search(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	int iter = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			iter++;
			return { true,iter };
		}
		else if (arr[mid] <= target) {
			left = mid + 1;
			iter++;
		}
		else {
			right = mid - 1;
			iter++;
		}

	}
	iter++;
	return { false, iter };
}