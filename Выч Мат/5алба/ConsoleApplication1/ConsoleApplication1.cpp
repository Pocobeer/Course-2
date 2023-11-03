#include<iostream>
#include <iomanip>
using namespace std;
double f(double x) {
	return pow(x,3) + 3*pow(x,2) -2;
}
double f1(double x) {
	return 3* pow(x, 2) + 6 * x ;
}
double f2(double x) {
	return 6 * x + 6;
}
int main() {
	setlocale(0, "rus");
	double a = 0, b = 1;
	int n = 0;
	double epsilon = 0.001;
	cout << "n " << "a " << "b " << "a-b" << endl;
	
	//double a1 = a, b1 = b;
	if (f(a) * f2(a) > 0) {
		cout << " а - касательная, b - хорда" << endl;
		do {
			double a1 = a, b1 = b;
			a = a1 - (f(a1) / f1(a1));
			b = a1 - (f(a1) / (f(b1) - f(a1)) * (b1 - a1));
			n++;
			cout << n  << fixed << " " << a << " " << b << " " << a - b << endl;
		} while (abs(a - b) > epsilon);
	}
	else {
		cout << " а - хорда , b - касательная" << endl;
		do {
			double a1 = a, b1 = b;
			a = a1 - (f(a1) / (f(b1) - f(a1)) * (b1 - a1));
			b = b1 - (f(b1) / f1(b1));
			n++;
			cout << n << " " << a << " " << b << " " << a - b << endl;
		} while (abs(a - b) > epsilon);
	}
	cout << "Ответ: " << a;
}