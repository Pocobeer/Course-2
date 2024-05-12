#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Введите размер поля n: ";
    cin >> n;

    // Минимальное количество архиепископов для покрытия поля
    int min_archbishops;

    // Для поля размером n x n, минимальное количество архиепископов будет равно
    // максимальному из количества слонов и коней
    min_archbishops = min(n, n * n / 2);

    cout << "Минимальное количество архиепископов для покрытия поля " << n << " x " << n << " равно " << min_archbishops << endl;

    return 0;
}
