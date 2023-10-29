#include<iostream>
#include<vector>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main() {
	//vector<vector<int» matrix;
	double matrix[10][10];
	srand(time(nullptr));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = rand() % 21 - 10;
		}
	}
	cout << "Current matrix: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << setw(5) << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0) {
				if (j == 0) matrix[i][j] = (matrix[i + 1][j] + matrix[i][j + 1]) / 2;
				if (j == 9) matrix[i][j] = (matrix[i][j - 1] + matrix[i + 1][j]) / 2;
				if (j > 0 && j < 9) matrix[i][j] = (matrix[i][j + 1] + matrix[i][j - 1] + matrix[i + 1][j]) / 2;
			}
			if (i == 9) {
				if (j == 0) matrix[i][j] = (matrix[i - 1][j] + matrix[i][j + 1]) / 2;
				if (j == 9) matrix[i][j] = (matrix[i][j - 1] + matrix[i - 1][j]) / 2;
				if (j > 0 && j < 9) matrix[i][j] = (matrix[i][j + 1] + matrix[i][j - 1] + matrix[i - 1][j]) / 2;
			}
			if (i > 0 && i < 9) {
				if (j == 0) matrix[i][j] = (matrix[i - 1][j] + matrix[i][j + 1] + matrix[i + 1][j]) / 2;
				if (j == 9) matrix[i][j] = (matrix[i][j - 1] + matrix[i - 1][j] + matrix[i + 1][j]) / 2;
				if (j > 0 && j < 9) matrix[i][j] = (matrix[i][j + 1] + matrix[i][j - 1] + matrix[i - 1][j] + matrix[i + 1][j]) / 2;
			}
		}
	}
	cout << "Matrix after smoothing: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//cout « fixed « (matrix[i][j]*100)/100 « " ";
			//printf("%.2f", matrix[i][j]);
			cout << setprecision(2) << setw(5) << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}