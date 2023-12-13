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
int bak(int a, int b) {
	return a + b;
}
typedef int (*ptr_bak)(int a, int b);
void func(ptr_bak bk) {
	cout << bk(20, 30) << endl;
}
int main()
{
	cout << sum() << endl;
	func(bak);
}

