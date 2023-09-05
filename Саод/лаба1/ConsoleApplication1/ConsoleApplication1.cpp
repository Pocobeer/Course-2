#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int main()
{
	vector<int> koloda = {0,1,2,3,4,5,6,7,8,9};
	int i;
	int index;
	int j;
	vector<int> koloda_A;
	vector<int> koloda_B;
	srand(time(0));
	int numberofElements = 5;
	while (numberofElements > 0) {
		int RandomIndex = rand() % koloda.size();
		index = RandomIndex;
		koloda_A.push_back(koloda[RandomIndex]);
		koloda.erase(koloda.begin() + index);
		numberofElements--;
	}
	int numberOfElements = 5;
	while (numberOfElements > 0) {
		int RandomIndex = rand() % koloda.size();
		index = RandomIndex;
		koloda_B.push_back(koloda[RandomIndex]);
		koloda.erase(koloda.begin() + index);
		numberOfElements--;
	}
	cout << "Game beginning:" << endl;
	cout << "Koloda A:\t" << "Koloda B: " << endl;
	for (i = 0; i < koloda_B.size(); i++) {
		cout << koloda_A[i] << "\t\t" << koloda_B[i] << endl;
	}
	if (koloda_A[0] > koloda_B[0]) {
		koloda_A.push_back(koloda_A[0]);
		koloda_A.push_back(koloda_B[0]);
		koloda_A.erase(koloda_A.begin());
		koloda_B.erase(koloda_B.begin());
	}
	cout << "Koloda A:" << endl;
	for (i = 0; i < koloda_A.size(); i++) {
		cout << koloda_A[i]  << endl;
	}
	cout << "Koloda B:" << endl;
	for (i = 0; i < koloda_B.size(); i++) {
		cout << koloda_B[i] << endl;
	}
}