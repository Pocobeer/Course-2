#pragma once

#include "all_includes.h"

class int_search : public BASIC_CLASS {
private:
    vector<int> data;
    int iterations = 0;
    int temp_iter = 0;
public:
    int_search(vector<int> &data) : data(data), iterations(0) {}

    string get_name() override {
        return "Интерполяционный поиск";
    }

    void change_isk(int isk) override {
        iterations = isk;
    }

    int solve() override {
        return solve(data[0]);
    }

    int solve(int key) override {
        int low = 0;
        int high = data.size() - 1;

        while (low <= high && key >= data[low] && key <= data[high]) {
            int pos = low + ((double)(high - low) / (data[high] - data[low])) * (key - data[low]);

            if (data[pos] == key) {
                iterations++;
                return data[pos];
            }

            if (data[pos] < key) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }

            iterations++;
        }
        return -1;
    }

    int get_iter() override {
        temp_iter = iterations;
        iterations = 0;
        return temp_iter;
    }

    void restruct(vector<int>& __a) override {
        data = __a;
    }
};
