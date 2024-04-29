#include <iostream>
#include <vector>

using namespace std;

// Структура для хранения позиции фигурки
struct Position {
    int x, y;
    Position(int _x, int _y) : x(_x), y(_y) {}
};

// Функция для проверки, можно ли поставить фигурку на данную позицию
bool isSafe(int x, int y, vector<Position>& positions) {
    for (const auto& pos : positions) {
        // Проверка, находится ли текущая позиция под угрозой от уже установленных фигурок
        if (x == pos.x || y == pos.y || abs(x - pos.x) == abs(y - pos.y) ||
            (abs(x - pos.x) == 1 && abs(y - pos.y) == 2) ||
            (abs(x - pos.x) == 2 && abs(y - pos.y) == 1))
            return false;
    }
    return true;
}

// Функция для рекурсивного поиска расстановок
void findConfigurations(int n, int row, vector<Position>& positions, vector<vector<Position>>& configurations) {
    // Если достигнут конец доски, добавляем текущую расстановку в результат
    if (row == n) {
        configurations.push_back(positions);
        return;
    }

    // Пробуем поставить фигурку в каждую клетку текущего ряда
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, positions)) {
            positions.push_back(Position(row, col)); // Добавляем фигурку
            findConfigurations(n, row + 1, positions, configurations); // Переходим к следующему ряду
            positions.pop_back(); // Удаляем фигурку перед возвратом
        }
    }
}

// Функция для вывода всех возможных расстановок
void printConfigurations(vector<vector<Position>>& configurations) {
    int count = 1;
    for (const auto& config : configurations) {
        cout << "Configuration " << count++ << ":\n";
        for (const auto& pos : config) {
            cout << "(" << pos.x << "," << pos.y << ") ";
        }
        cout << "\n\n";
    }
}
int main() {
    int n = 8; // Размер доски
    vector<Position> positions; // Вектор для хранения позиций фигурок
    vector<vector<Position>> configurations; // Вектор для хранения всех расстановок
    findConfigurations(n, 0, positions, configurations);

    if (!configurations.empty()) {
        cout << "Minimum number of figures: " << configurations[0].size() << "\n";
        cout << "Number of configurations: " << configurations.size() << "\n";
        printConfigurations(configurations);
    }
    else {
        cout << "No valid configurations found.\n";
    }

    return 0;
}