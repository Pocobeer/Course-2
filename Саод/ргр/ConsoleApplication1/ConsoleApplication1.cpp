#include <iostream>
#include <cmath>

using namespace std;

int minKnights(int n) {
    // Для четного n количество черных и белых клеток одинаково
    // Для нечетного n количество черных и белых клеток отличается на 1
    int black = n / 2;
    int white = (n % 2 == 0) ? black : black + 1;
    // Минимальное количество коней - максимум из черных и белых клеток, умноженное на n
    return max(black, white) * n;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер доски n x n: ";
    cin >> n;
    // Находим минимальное количество фигур (коней)
    int min_figures = minKnights(n);
    cout << "Минимальное количество коней для покрытия всех клеток: " << min_figures << endl;
    return 0;
}
