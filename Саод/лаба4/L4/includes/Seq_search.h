#pragma once

#include "all_includes.h"

class seq_search : public BASIC_CLASS {
public:
    seq_search(vector<int> &a) {
        VEC = a;
    }
    seq_search(vector<int>& a, int isk_) {
        VEC = a;
        ISKOMOE = isk_;
    }
    seq_search(){}
    string get_name() override {
        return NAME;
    }
    void change_isk(int isk_) override {
        ISKOMOE = isk_;
    }
    int solve() override {
        for (const auto& a : VEC) {
            //ITER_COUNT++;
            if (a == ISKOMOE) {
                ITER_COUNT++;
                return a;
            }
            if (a > ISKOMOE) {
                ITER_COUNT++;
                return -1;
            }
            ITER_COUNT++;

        }
        return -1;
    }
    int solve(int isk_) {
        change_isk(isk_);
        return solve();
    }
    int get_iter() {
        int temp_i = ITER_COUNT-1;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& a) {
        VEC = a;
    }
private:
    vector<int> VEC;
    int ISKOMOE = -1;
    string NAME = "Последовательный поиск";
    int ITER_COUNT = 0;
};