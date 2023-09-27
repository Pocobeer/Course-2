#include<iostream>
using namespace std;
int main() {
	double x1 = 0;
	double x2 = 0;
	double x3 = 0;
	double E = 0.0001;
	double x1_o;
	double x2_o;
	double x3_o;
	int a = 0;
	do {
		x1_o = x1;
		x2_o = x2;
		x3_o = x3;
		x1 = 0.24 * x1_o - 0.05 * x2_o - 0.24 * x3_o + 0.19;
		x2 = -0.22 * x1 + 0.09 * x2_o - 0.44 * x3_o +0.97;
		x3 = 0.13 * x1 - 0.02 * x2 + 0.42 * x3_o - 0.14;
		cout << a << ": " << x1 << " " << x2 << " " << x3 << " " << endl;
		a++;
	} while ((abs(x1_o - x1) > E) || (abs(x2_o - x2) > E) || (abs(x3_o - x3) > E));
}