#pragma once
#include "all_includes.h"

class fib_search : public BASIC_CLASS {
private:
    int ITER_COUNT = 0;
    void up() {
        if (p == 1) {
            STOP = true;
        }
        i = i + q;
        p = p - q;
        q = q - p;
    }
    void down() {
        if (q == 0) {
            STOP = true;
        }
        i = i - q;
        int temp = q;
        q = p - q;
        p = temp;
    }

    bool STOP = false;
    vector<int> FIB{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };
    int i, k, n, m, p, q;

    vector<int> VEC;
    string NAME = "Поиск Фибоначчи";
    int ISKOMOE = -1;
public:
    fib_search(vector<int>& a) {
        VEC = a;
        STOP = false;
        k = 0;
        n = VEC.size();
        while (F(k + 1) < n)
            k += 1;
        m = F(k + 1) - (n + 1);
        i = F(k) - m;
        p = F(k - 1);
        q = F(k - 2);
    }
    fib_search(vector<int>& a, int isk_) : fib_search(a) {
        ISKOMOE = isk_;
    }
    string get_name() override {
        return NAME;
    }
    void change_isk(int isk) override {
        ISKOMOE = isk;

        k = 0;
        n = VEC.size();
        while (F(k + 1) < n)
            k += 1;
        m = F(k + 1) - (n + 1);
        i = F(k) - m;
        p = F(k - 1);
        q = F(k - 2);
    }
    int F(int a) {
        if (a < FIB.size()) {
            return FIB[a];
        }
        else {
            for (int i = FIB.size() - 2; i != a; i++) {
                FIB.push_back(FIB[i] + FIB[i + 1]);
            }
            return FIB[a];
        }
    }
    int solve() override {
        int RES = -1;
        while (!STOP) {
            ITER_COUNT++;
            if (i < 0) {
                up();
            }
            else if (i >= n) {
                down();
            }
            else if (VEC[i] == ISKOMOE) {
                STOP = false;
                return VEC[i];
            }
            else if (ISKOMOE < VEC[i]) {
                down();
            }
            else if (ISKOMOE > VEC[i]) {
                up();
            }
        }
        STOP = false;
        return RES;
    }
    int solve(int isk_) {
        change_isk(isk_);
        return solve();
    }
    int get_iter() {
        int temp_i = ITER_COUNT;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& a) {
        VEC = a;
        STOP = false;
        k = 0;
        n = VEC.size();
        while (F(k + 1) < n)
            k += 1;
        m = F(k + 1) - (n + 1);
        i = F(k) - m;
        p = F(k - 1);
        q = F(k - 2);
    }
};