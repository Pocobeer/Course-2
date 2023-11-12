#include <iostream>
#include <vector>
#include <limits>

const int MAXN = 100;
int cost[MAXN][MAXN];  // Максимальное количество работников и работ

int n; // количество работников

int minCost(int worker, std::vector<bool>& assigned, std::vector<int>& assignment) {
    if (worker == n) {
        int totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalCost += cost[i][assignment[i]];
        }
        return totalCost;
    }

    int min_cost = std::numeric_limits<int>::max();

    for (int job = 0; job < n; ++job) {
        if (!assigned[job]) {
            assigned[job] = true;
            assignment[worker] = job;
            int current_cost = minCost(worker + 1, assigned, assignment);
            if (current_cost < min_cost) {
                min_cost = current_cost;
            }
            assigned[job] = false;
        }
    }

    return min_cost;
}

int main() {
    // Инициализация стоимости назначения работников на работы
    // cost[i][j] - стоимость назначения i-го работника на j-ю работу
    cost[0][0] = 3; cost[0][1] = 4; cost[0][2] = 1;
    cost[1][0] = 2; cost[1][1] = 5; cost[1][2] = 6;
    cost[2][0] = 7; cost[2][1] = 0; cost[2][2] = 2;

    n = 3;  // количество работников

    std::vector<bool> assigned(n, false); // флаги, указывающие, назначен ли работник на работу
    std::vector<int> assignment(n);  // назначения работников на работы

    int totalCost = minCost(0, assigned, assignment);

    std::cout << "Assignment: ";
    for (int i = 0; i < n; ++i) {
        std::cout << "(" << i << ", " << assignment[i] << ") ";
    }
    std::cout << "with total cost " << totalCost << std::endl;

    return 0;
}
