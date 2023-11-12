#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N; // Заданный параметр N
    cout << "Enter N: " << endl;
    cin >> N;
    vector<int> mersenneNumbers;

    for (int p = 2; p < N; ++p) {  // Перебираем все числа до N
        if (isPrime(p)) {  // Проверяем, является ли p простым числом
            int mersenne = pow(2, p) - 1;
            if (mersenne < 0) continue;
            if (mersenne < N) {
                mersenneNumbers.push_back(mersenne);
            }
        }
    }

    cout << "Mersenn's numbers less than " << N << ":\n";
    for (int num : mersenneNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
