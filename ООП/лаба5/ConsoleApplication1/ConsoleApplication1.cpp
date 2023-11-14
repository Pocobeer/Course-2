#include<iostream>
#include<iomanip>
using namespace std;
void laba_2(double x1, double x2, double eps) {
	double dx = 0.1;
	cout << "Значение x:" << setw(25) << "Приближенное значение f(x):" << setw(25) << "Истинное значение f(x)" << setw(20) << "Количество элементов:" << endl;
	for (double x = x1; x < x2; x += dx) {
		double result = 0.0;
		int n = 0;
		double function = 0.0;
		do {
			if (n >= 200) {
				function = 0;
				break;
			}
			function += result;
			result = pow(x, 2 * n + 1) / (2 * n + 1);
			n++;
		} while (fabs(result) >= eps);
		if (x == x1) cout << "\n";
		cout << fixed << left << setw(25) << x << setw(20) << function << setw(20) << atanh(x) << setw(20) << n << endl;
	}
}
void print_arr(const int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Zadanie_2(void(*ptr_2)(double, double, double), double x1, double x2, double eps) {
	ptr_2(x1, x2, eps);
}
int max_abs(int* arr, int SIZE) {
	int maxabs = 0;
	for (int i = 0; i < SIZE; i++) {
		if (abs(arr[i]) > maxabs) maxabs = arr[i];
		//if (abs(*(arr+i)) > maxabs) maxabs = *(arr+i);
	}
	return maxabs;
}
int sum_elements_between_positive(int* arr, int size) {
	int sum = 0;
	bool f1 = false, f2 = false;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) > 0) {
			if (f1) f2 = true;
			if (!f1) {
				f1 = true;
				continue;
			}
		}
		if (f1 && !f2) {
			sum += *(arr + i);
		}
	}
	return sum;
}
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Звдвние 1: " << endl;
	laba_2(-1, 1, 1e-3);
	cout << "Задание 2: " << endl;
	Zadanie_2(laba_2, -1, 1, 1e-3);
	cout << "Задание 3: " << endl;
	int array[] = { 1,-2,-3,-4,5 };
	int array_size = sizeof(array)/sizeof(array[0]);//??????????????????????
	cout << "Array: " << endl;
	print_arr(array, array_size);
	cout << "Сумма между положительными числами: " << sum_elements_between_positive(array, array_size) << endl;
	cout << "Максимальное по модулю число: " << max_abs(array, array_size) << endl;
}
