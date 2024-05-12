
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

class MonteCarloChessSolver {
private:
    int size;
    int attempts;
    vector<vector<bool>> board;
    vector<pair<int, int>> bishops;
    mt19937 rng{ random_device{}() }; // Mersenne Twister RNG

public:
    MonteCarloChessSolver(int n) : size(n), attempts(0), board(n, vector<bool>(n, false)) {}

    bool isSafe(int x, int y) {
        // Check diagonals
        for (const auto& bishop : bishops) {
            if (abs(x - bishop.first) == abs(y - bishop.second))
                return false;
        }
        return true;
    }

    void placeBishops() {
        bishops.clear();
        for (int i = 0; i < size; ++i) {
            int x = uniform_int_distribution<int>{ 0, size - 1 }(rng);
            int y = uniform_int_distribution<int>{ 0, size - 1 }(rng);
            if (isSafe(x, y)) {
                bishops.emplace_back(x, y);
                board[x][y] = true;
            }
        }
    }

    void solve() {
        auto start = chrono::high_resolution_clock::now();
        while (true) {
            placeBishops();
            attempts++;
            if (bishops.size() == size) break; // All bishops placed
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "Solution found in " << attempts << " attempts." << endl;
        cout << "Time taken: " << duration << " milliseconds." << endl;
    }

    friend ostream& operator<<(ostream& os, const MonteCarloChessSolver& solver) {
        for (int i = 0; i < solver.size; ++i) {
            for (int j = 0; j < solver.size; ++j) {
                if (solver.board[i][j])
                    os << "B ";
                else
                    os << "_ ";
            }
            os << endl;
        }
        return os;
    }
};
int main()
{
    setlocale(0, "");
    int boardSize;
    cout << "Enter the size of the chessboard: ";
    cin >> boardSize;

    MonteCarloChessSolver solver(boardSize);
    solver.solve();

    cout << "Solution:" << endl;
    cout << solver;

}
