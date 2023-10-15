#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main() {
	//vector<vector<int>> matrix;
	int matrix[10][10];
	srand(time(nullptr));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = rand() % 21 - 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}