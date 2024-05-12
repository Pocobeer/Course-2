#include <iostream>

using namespace std;

int minBishops(int n) {
    return n; // Минимальное количество слонов для покрытия всех клеток
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер доски n x n: ";
    cin >> n;
    int min_bishops = minBishops(n);
    cout << "Минимальное количество слонов для покрытия всех клеток: " << min_bishops << endl;
    return 0;
}