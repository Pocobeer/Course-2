#include <iostream>
using namespace std;
int main()
{
    int A, B;
    cout << "Enter A: " << endl;
    cin >> A;
    cout << "Enter B: " << endl;
    bool sravn = false;
    if (A > B) sravn = true;
    int count = 0;
    for (int i = -1000; i <= 1000; i++) {
        if (sravn == true) {
            if (A > i) count++;
        }
        else {
            if (B > i) count++;
        }
    }
    cout << "Serial number = " << count << endl;
}

