#pragma once

#include "all_includes.h"

#pragma once
#include "all_includes.h"

class fib_sea_wo : public BASIC_CLASS {
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
    string NAME = "Фибоначчи без проверки";
    int ISKOMOE = -1;
public:
    fib_sea_wo(vector<int>& a) {
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
    fib_sea_wo(vector<int>& a, int isk_) : fib_sea_wo(a) {
        ISKOMOE = isk_;
    }
    string get_name() override {
        return NAME;
    }
    void change_isk(int isk) override {
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
        return -1;
    }

    int solve(int isk_) {
        int q = 0;
        int p = 1;
        int i = q + p;
        int temp = 0;
        n = VEC.size() - 1;
        while (i < n - i) {
            q = p;
            p = i;
            i = p + q;
        }

        while (p >= 1 && q >= 0) {
            if (isk_ == VEC[i]) {
                ITER_COUNT++;
                return ++temp;
            }
            else if (isk_ > VEC[i]) {
                i += q;
                p -= q;
                q -= p;
                ++temp;
                ITER_COUNT++;
            }
            else if (isk_ < VEC[i]) {
                i -= q;
                int t = p - q;
                p = q;
                q = t;
                ++temp;
                ITER_COUNT++;
            }
        }
        return -1;
    }
    int get_iter() {
        int temp_i = ITER_COUNT;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& a) {
    }
};