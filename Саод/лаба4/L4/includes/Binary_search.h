#pragma once

#include "all_includes.h"

class bin_search : public BASIC_CLASS {
public:
    void restruct(vector<int>& a) {
        VEC = a;
    }
    bin_search(vector<int> &a) {
        VEC = a;
    }
    bin_search(vector<int> &a, int isk_) {
        VEC = a;
        ISKOMOE = isk_;
    }
    bin_search() {}
    string get_name() {
        return NAME;
    }
    void change_isk(int isk_) {
        ISKOMOE = isk_;
    }
    int solve() override {
        int l = 0, r = VEC.size() - 1;

        while (r > l) {
            int m = (l + r) / 2;

            if (VEC[m] < ISKOMOE) {
                l = m + 1;
                ITER_COUNT++;
            }
            else if (VEC[m] > ISKOMOE) {
                r = m - 1;
                ITER_COUNT++;
            }
            else {
                return VEC[m];
            }
        }
        if (VEC[l] == ISKOMOE) {
            ITER_COUNT++;
            return VEC[l];
        }
        else {
            return -1;
        }
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
private:
    int ISKOMOE = -1;
    string NAME = "Бинарный поиск";
    vector<int> VEC;
    int ITER_COUNT = 0;
};