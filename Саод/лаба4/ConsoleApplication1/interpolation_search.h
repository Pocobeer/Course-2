#pragma once
int up_4 = 0, bp_4 = 0;
std::pair<bool, int> interpolation_saerch(int arr[], int size, int target) {
	int iter = 0;
	int left = 0;
	int right = size - 1;
	while (left <= right && target >= arr[left] && target <= arr[right]) {
		int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
		if (arr[pos] == target) {
			iter++;
			return  { true, iter };
		}
		else if (arr[pos] < target) {
			left = pos + 1;
			iter++;
		}
		else {
			right = pos - 1;
			iter++;
		}
	}
	iter++;
	return  { false, iter };
}