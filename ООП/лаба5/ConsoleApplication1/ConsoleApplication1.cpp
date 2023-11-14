#include<iostream>
#include<iomanip>
using namespace std;
void laba_2(double , double , double );

int main() {
	double x1 = -1, x2 = 1, eps = 1e-3;
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
void laba_2(double arg1, double arg2, double arg3) {

}