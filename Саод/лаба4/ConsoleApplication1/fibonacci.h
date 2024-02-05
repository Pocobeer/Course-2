#pragma once

int fibonacci_search(int target) {
	if (target <= 0) {
		return -1;
	}
	else if (target == 1 || target == 2) {
		return 1;
	}
	else {
		int* fib = new int[target + 1];
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