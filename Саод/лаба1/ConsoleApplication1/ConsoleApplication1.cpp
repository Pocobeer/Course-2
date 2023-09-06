#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> koloda = {0,1,2,3,4,5,6,7,8,9};
	int i;
	int index;
	int j;
	int ind = 10;
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
	if (koloda_A[0] == -1) {
		auto a = partition(koloda_B.begin(), koloda_B.end(), [](int num) {
			return num != -1;
			});
	}
	else {
		auto a = partition(koloda_A.begin(), koloda_A.end(), [](int num) {
			return num != -1;
			});
	}
	while(koloda_A[0]!=-1 || koloda_B[0] != -1) {
		if ((koloda_A[0] > koloda_B[0]) || (koloda_A[0] == 0 && koloda_B[0] == 9)) {
			
			koloda_A.push_back(koloda_A[0]);
			koloda_A.push_back(koloda_B[0]);
			koloda_A.erase(koloda_A.begin());
			koloda_B.erase(koloda_B.begin());
			koloda_B.push_back(-1);
			koloda_B.push_back(-1);
			auto a = partition(koloda_B.begin(), koloda_B.end(), [](int num) {
				return num != -1;
				});
			auto b = partition(koloda_A.begin(), koloda_A.end(), [](int num) {
				return num != -1;
				});
		}
		else {
			
			koloda_B.push_back(koloda_A[0]);
			koloda_B.push_back(koloda_B[0]);
			koloda_A.erase(koloda_A.begin());
			koloda_B.erase(koloda_B.begin());
			koloda_A.push_back(-1);
			koloda_A.push_back(-1);
			auto a = partition(koloda_A.begin(), koloda_A.end(), [](int num) {
				return num != -1;
				});
			auto b = partition(koloda_B.begin(), koloda_B.end(), [](int num) {
				return num != -1;
				});
		}
	
		/*cout << koloda_A.size() << "bebe" << koloda_B.size() << endl;
		
		if (koloda_A.size() > koloda_B.size()) {
			cout << "Koloda A:\t" << "Koloda B" << endl;
			for (i = 0; i < koloda_A.size(); i++) {
				cout << koloda_A[i] << "\t\t" << koloda_B[i] << endl;
			}
		}
		else {
			cout << "Koloda A:\t" << "Koloda B" << endl;
			for (i = 0; i < koloda_B.size(); i++) {
				cout << koloda_A[i] << "\t\t" << koloda_B[i] << endl;
			}
		}
		cout << koloda_A.size() << "bebe" << koloda_B.size() << endl;*/
		if (koloda_A[0] == -1 || koloda_B[0] == -1) break;
	}
	    /*if (koloda_A.size() > 10) {
		koloda_A.erase(koloda_A.begin() + ind, koloda_A.end());
	}
	if (koloda_B.size() > 10) {
		koloda_B.erase(koloda_B.begin() + ind, koloda_B.end());
	}*/
	cout << "Endgame:" << endl;
	for (i = 0; i < 10; i++) {
		cout << koloda_A[i] << "\t\t" << koloda_B[i] << endl;
	}
}