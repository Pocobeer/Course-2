#include <iostream>
using namespace std;

int *sum() {
    int var = 16;
    return &var;
}
int summa(const int* arr, const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}
int summa1(const int** arr, const int rows, const int columns)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			sum += arr[i][j];
	return sum;
}

struct structure {
	int a;
	int b;
	int operator * (structure& a) {
		return (this->a * a.b);
	}
};

int bak(int a, int b) {
	return a + b;
}
typedef int (*ptr_bak)(int a, int b);
void func(ptr_bak bk) {
	cout << bk(20, 30) << endl;
}
struct pr_1 {
	int c;
	pr_1 operator * (pr_1& c) {
		int temp = this->c * c.c;
		this->c = temp;
		return *this;
	}
};
template < typename T> T pr(T arg_1, T arg_2) {
	return arg_1 * arg_2;
}
int main()
{
	structure n1{ 20, 30 };
	structure n2{ 40,50 };
	cout << n1 * n2 << endl;
	cout << sum() << endl;
	func(bak);
	pr_1 n_1{ 3 };
	pr_1 n_2{ 8 };
	cout << pr(20.1, 30.5) << endl;
	//cout << n_1 * n_2;
	cout << pr(n_1, n_2).c;
}

