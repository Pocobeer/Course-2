#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    int m = 0;
    while (true) {
        m++;
        if (is_prime(m) && is_prime(2 * m - 1)) {
            if (m > n) {
                break;
            }
            cout << m << " ";
            
        }
    }

    return 0;
}