#pragma once
int up_1 = 0, bp_1 = 0;
std::pair<bool, int> search(int arr[], int size, int target) {
	int iter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			iter++;
			return std::make_pair(true,iter);

		}
		iter++;
		if (arr[i] > target) break;
	}
	iter++;
	return {false, iter};
}