#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Размер доски

// Структура для представления клетки на доске
struct Cell {
    int row;
    int col;
};

// Функция для проверки, находится ли данная клетка в угрозе бишопов
bool isUnderAttack(int row, int col, const vector<Cell>& bishops) {
    for (const auto& bishop : bishops) {
        if (abs(row - bishop.row) == abs(col - bishop.col)) {
            return true;
        }
    }
    return false;
}

// Функция для нахождения расстановки архиепископов на доске
bool findBishopsPlacement(int row, vector<Cell>& bishops, vector<vector<bool>>& board) {
    if (row >= N) {
        return true; // Все строки проверены
    }

    for (int col = 0; col < N; col++) {
        if (!isUnderAttack(row, col, bishops) && !board[row][col]) {
            // Помечаем все атакуемые бишопами клетки
            for (int i = 0; i < N; i++) {
                if (!board[i][col]) board[i][col] = true;
                if (!board[row][i]) board[row][i] = true;
                int j = row + i, k = col + i;
                if (j < N && k < N && !board[j][k]) board[j][k] = true;
                j = row - i, k = col + i;
                if (j >= 0 && k < N && !board[j][k]) board[j][k] = true;
                j = row + i, k = col - i;
                if (j < N && k >= 0 && !board[j][k]) board[j][k] = true;
                j = row - i, k = col - i;
                if (j >= 0 && k >= 0 && !board[j][k]) board[j][k] = true;
            }

            // Добавляем текущего бишопа в список
            bishops.push_back({ row, col });

            // Рекурсивно ищем расстановку для следующей строки
            if (findBishopsPlacement(row + 1, bishops, board)) {
                return true;
            }

            // Если расстановка не удалась, убираем текущего бишопа из списка и отмечаем его клетки как свободные
            for (int i = 0; i < N; i++) {
                if (!board[i][col]) board[i][col] = false;
                if (!board[row][i]) board[row][i] = false;
                int j = row + i, k = col + i;
                if (j < N && k < N && !board[j][k]) board[j][k] = false;
                j = row - i, k = col + i;
                if (j >= 0 && k < N && !board[j][k]) board[j][k] = false;
                j = row + i, k = col - i;
                if (j < N && k >= 0 && !board[j][k]) board[j][k] = false;
                j = row - i, k = col - i;
                if (j >= 0 && k >= 0 && !board[j][k]) board[j][k] = false;
            }
            bishops.pop_back();
        }
    }

    return false; // Не удалось найти подходящую расстановку
}

int main() {
    vector<Cell> bishops; // Список расположений архиепископов
    vector<vector<bool>> board(N, vector<bool>(N, false)); // Доска, на которой отмечены клетки, атакуемые архиепископами

    // Находим расстановку архиепископов
    findBishopsPlacement(0, bishops, board);

    // Выводим результат
    cout << "Расстановка архиепископов:" << endl;
    for (const auto& bishop : bishops) {
        cout << "(" << bishop.row << ", " << bishop.col << ")" << endl;
    }

    return 0;
}