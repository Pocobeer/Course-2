#include <iostream>
#include <vector>

using namespace std;

int n, c = 0;
vector <int> perm;
vector <bool> used;

void print_table() {
    c++;
    cout << c << ")\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (perm[i] == j) {
                printf("L");
            }
            else {
                printf("*");
            }
        }
        puts("");
    }
}

void generate(int pos) {
    if (pos == n + 1) {
        print_table();
        puts("");
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                perm[pos] = i;
                generate(pos + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    n = 6;
    perm = vector <int>(n + 1);
    used = vector <bool>(n + 1);
    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
        used[i] = false;
    }

    for (int i = 1; i < 2; i++) {
        generate(i);
    }

    cout << "Всего расстановок: " << c << endl;
    return 0;
}