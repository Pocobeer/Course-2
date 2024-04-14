#pragma once
#include "all_includes.h"

class fast_sort_iter : public BASIC_CLASS {
private:
    vector<int> VEC = {};

    int partition(vector<int>& arr, int low, int high, data& d) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            d.count_of_compare++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                d.count_of_assign += 3; // Incrementing by 3 due to 3 swap operations
            }
        }
        swap(arr[i + 1], arr[high]);
        d.count_of_assign += 3; // Incrementing by 3 for the final swap operation
        return i + 1;
    }

public:
    fast_sort_iter(vector<int> arr){
        VEC = arr;
    }
    string name = "Быстрая сортировка итерациями";
    string get_name() {
        return name;
    }
    BASIC_CLASS::data sort() override {
        data mydata = data();

        Timer timer;
        int low = 0, high = int(VEC.size()) - 1;
        vector<pair<int, int>> stack;
        stack.push_back({ low, high });

        while (!stack.empty()) {
            low = stack.back().first;
            high = stack.back().second;
            stack.pop_back();

            if (low < high) {
                int pi = partition(VEC, low, high, mydata);
                stack.push_back({ low, pi - 1 });
                stack.push_back({ pi + 1, high });
            }
        }
        mydata.time += timer.elapsed();
        return mydata;
    }
};