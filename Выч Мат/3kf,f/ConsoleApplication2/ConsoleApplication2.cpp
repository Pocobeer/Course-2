#include<iostream>
using namespace std;
int main() {
	double x1 = 1;
	double x2 = 1;
	double x3 = 1;
	double E = 0.0001;
	double x1_o;
	double x2_o;
	double x3_o;
	int a = 0;
	do {
		x1_o = x1;
		x2_o = x2;
		x3_o = x3;
		x1 = 0.37 * x1_o + 0.18 * x2_o + 0.28 * x3_o + 0.42;
		x2 = 0.12 * x1 + 0.19 * x2_o - 0.14 * x3_o + 0.38;
		x3 = -0.42 * x1 - 0.09 * x2 + 0.48 * x3_o - 0.06;
		cout << a << ": " << x1 << " " << x2 << " " << x3 << " " << endl;
		a++;
	} while ((abs(x1_o - x1) > E) || (abs(x2_o - x2) > E) || (abs(x3_o - x3) > E));
}