#include<iostream>
#include<iomanip>
#include<random>
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
void Zadanie_2(void(*ptr_2)(double, double, double), double x1, double x2, double eps) {
	ptr_2(x1, x2, eps);
}

int char_count(const char* str) {
	int count = 0;
	for (str; *str != '\0'; str++) {
		if (*str >= 48 && *str <= 57) {
			count++;
		}
	}
	return count;
}
double rand_num(double start, double end) {
	return rand() % (int)(end - start + 1) + start;
	//return rand() * (end - start) / RAND_MAX + start;
}
void rand_matrix(double** m, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			m[i][j] = rand_num(0, 100);
		}
	}
}
void print_matrix(double** m, int rows, int columns) {
	cout << "Matrix: " << "\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << int(m[i][j]) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void smooth(double** m, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == 0) {
				if (j == 0) m[i][j] = (m[i + 1][j] + m[i][j + 1]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i + 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i + 1][j]) / 2;
			}
			if (i == 4) {
				if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j]) / 2;
			}
			if (i > 0 && i < 4) {
				if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1] + m[i + 1][j]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
			}
		}
	}
}
struct Structure {
	int a;
	int b;
};
void struct_print(Structure s) {
	cout << s.a << endl << s.b << endl;
}
void sort_arr(int* arr, int size, int k = 0) {
	if (k < size) {
		for (int i = 0; i < size-1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		
		sort_arr(arr, size, ++k);//?????????????????????????
	}
}
void print_arr(const double* arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
double max_abs(double* arr, int SIZE) {
	double maxabs = 0;
	for (int i = 0; i < SIZE; i++) {
		if (abs(arr[i]) > maxabs) maxabs = arr[i];
		//if (abs(*(arr+i)) > maxabs) maxabs = *(arr+i);
	}
	return maxabs;
}
double sum_elements_between_positive(double* arr, int size) {
	double sum = 0;
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
template<class Type> void smooth_9(Type** m, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == 0) {
				if (j == 0) m[i][j] = (m[i + 1][j] + m[i][j + 1]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i + 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i + 1][j]) / 2;
			}
			if (i == 4) {
				if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j]) / 2;
			}
			if (i > 0 && i < 4) {
				if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1] + m[i + 1][j]) / 2;
				if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
				if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
			}
		}
	}
}
template<class Rand> void rand_matrix_9(Rand** m, int rows, int columns) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			m[i][j] = rand_num(0.0, 100.0);
		}
	}
}
template<class Print> void print_matrix_9(Print** m, int rows, int columns) {
	cout << "Matrix: " << "\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << int(m[i][j]) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
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
	cout << "Задание 4: " << endl;
	const char* char_ptr = "qwe45k s54a 3d4k24ksdk";
	cout << "Строка : " << char_ptr << endl;
	cout << "Колво чисел в строке: " << char_count(char_ptr) << endl;
	cout << "Задание 5: " << endl;
	int rows = 5, columns = 5;
	double** mass = new double* [rows];
	for (int i = 0; i < rows; i++) {
		mass[i] = new double[columns];
	}
	rand_matrix(mass, rows, columns);
	print_matrix(mass, rows, columns);
	smooth(mass, rows, columns);
	print_matrix(mass, rows, columns);
	for (unsigned i{}; i < rows; i++) // delete dynamic massive
	{
		delete[] mass[i];
	}
	delete[] mass;
	cout << "Задание 6: " << endl;
	Structure f;
	f.a = 10;
	f.b = 5;
	struct_print(f);
	cout << "Задание 7: " << endl;
	cout << "Array: " << endl;
	print_arr(array, array_size);
	cout << array_size << endl;
	sort_arr(array, array_size);
	cout << "Array after sort: " << endl;
	print_arr(array, array_size);
	cout << "Задание 8: " << endl;
	cout << "Array_int: " << endl;
	int array1[] = { 1,-2,-3,-4,5 };
	print_arr(array1, array_size);
	cout << "Сумма между положительными числами: " << sum_elements_between_positive(array1, array_size) << endl;
	cout << "Максимальное по модулю число: " << max_abs(array1, array_size) << endl;
	double array2[] = { 1.4,-2.6,-3.8,-4.4,5.5 };
	cout << "Array_double: " << endl;
	print_arr(array2, array_size);
	cout << "Сумма между положительными числами: " << sum_elements_between_positive(array2, array_size) << endl;
	cout << "Максимальное по модулю число: " << max_abs(array2, array_size) << endl;
	cout << "Задание 9: " << endl;
	int** mass_int = new int* [rows];
	for (int i = 0; i < rows; i++) {
		mass_int[i] = new int[columns];
	}
	double** mass_double = new double* [rows];
	for (int i = 0; i < rows; i++) {
		mass_double[i] = new double[columns];
	}
	rand_matrix_9(mass_int, rows, columns);
	print_matrix_9(mass_int, rows, columns);
	smooth_9(mass_int, rows, columns);
	print_matrix_9(mass_int, rows, columns);
	for (unsigned i{}; i < rows; i++) // delete dynamic massive
	{
		delete[] mass_int[i];
	}
	delete[] mass_int;
	rand_matrix_9(mass_double, rows, columns);
	print_matrix_9(mass_double, rows, columns);
	smooth_9(mass_double, rows, columns);
	print_matrix_9(mass_double, rows, columns);
	for (unsigned i{}; i < rows; i++) // delete dynamic massive
	{
		delete[] mass_double[i];
	}
	delete[] mass_double;
}
