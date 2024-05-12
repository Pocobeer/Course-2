#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int x, y;
};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void markThreatened(vector<vector<bool>>& board, int x, int y, int n) {
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Помечаем клетки, угрожаемые конем
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n)) {
            board[nx][ny] = true;
        }
    }

    // Помечаем клетки, угрожаемые слоном
    for (int i = -n; i <= n; ++i) {
        int nx = x + i;
        int ny1 = y + i;
        int ny2 = y - i;
        if (isValid(nx, ny1, n)) {
            board[nx][ny1] = true;
        }
        if (isValid(nx, ny2, n)) {
            board[nx][ny2] = true;
        }
    }
}

int minKnights(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    int knights = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!board[i][j]) {
                markThreatened(board, i, j, n);
                knights++;
            }
        }
    }

    return knights;
}

int main() {
    int n = 8; // Размер доски 8*8

    cout << "Minimum number of pieces required on an " << n << "x" << n << " chessboard: " << minKnights(n) << endl;

    return 0;
}
