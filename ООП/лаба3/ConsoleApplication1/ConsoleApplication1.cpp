#include<iostream>
#include<vector>
#include<random>
using namespace std;
int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(-100, 100);
    int n;
	int maxabs = 0;
	int positiveNum;
	int negativeSum = 0;
	vector<int> arr;
	cout << "Enter n: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int randNum = dist(gen);
		arr.push_back(randNum);
	}
	bool f1 = false, f2 = false; int sum = 0;//f1 - 1 positive, f2 - 2 positive
	cout << "Vector including numbers: " << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
		if (abs(arr[i]) > maxabs) maxabs = arr[i];
		if (arr[i] > 0) {
			if (f1) f2 = true;
			if (!f1) {
				f1 = true;
				continue;
			}
		}
		if (f1&&!f2) {
			sum += arr[i];
		}
	}
	cout << endl;
	cout << "Max abs element: " << maxabs << endl;
	cout << "Sum between 1st and 2nd positive numbers: " << sum << endl;
}