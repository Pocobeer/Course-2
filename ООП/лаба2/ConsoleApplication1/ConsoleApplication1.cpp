#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double x1 = -1.5;
	double x2 = 1.5;
	double dx;
	double epsilon = 1e-6;
	cout << "Введите длину шага: " << endl;
	cin >> dx;
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
		} while (fabs(result) >= epsilon);
		if (x == x1) cout << "\n";
		cout << fixed << left << setw(25) << x << setw(20) << function << setw(20) << atanh(x) << setw(20) << n << endl;
	}
}