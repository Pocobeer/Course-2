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
	while(koloda_A[0]!=-1 || koloda_B[0] != -1) {
		if ((koloda_A[0] > koloda_B[0]) || (koloda_A[0] == 0 && koloda_B[0] == 9)) {
			koloda_A.push_back(koloda_A[0]);
			koloda_A.push_back(koloda_B[0]);
			koloda_A.erase(koloda_A.begin());
			koloda_B.erase(koloda_B.begin());
			koloda_B.push_back(-1);
			koloda_B.push_back(-1);

		}
		else {
			koloda_B.push_back(koloda_A[0]);
			koloda_B.push_back(koloda_B[0]);
			koloda_A.erase(koloda_A.begin());
			koloda_B.erase(koloda_B.begin());
			koloda_A.push_back(-1);
			koloda_A.push_back(-1);
		}
		cout << koloda_A.size() << "bebe" << koloda_B.size() << endl;
		/*int a = 0, b = 0, c = 0, d = 0;
		while (b < koloda_A.size()) {
			if (koloda_A[b] != -1) {
				koloda_A[a] = koloda_A[b];
				b++;
			}
			b++;
		}
		while (a < koloda_A.size()) {
			koloda_A[a] = -1;
			a++;
		}
		while (d < koloda_B.size()) {
			if (koloda_B[d] != -1) {
				koloda_B[c] = koloda_B[d];
				d++;
			}
			d++;
		}
		while (c < koloda_B.size()) {
			koloda_B[c] = -1;
			c++;
		}*/
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
		cout << koloda_A.size() << "bebe" << koloda_B.size() << endl;
		if (koloda_A[0] == -1 || koloda_B[0] == -1) break;
	}
}