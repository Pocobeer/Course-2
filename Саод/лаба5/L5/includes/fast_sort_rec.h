#pragma once
#include "all_includes.h"


class fast_sort_rec : public BASIC_CLASS {
private:
    vector<int> VEC = {};

    void quicksort(vector<int>& arr, int left, int right, data& d) {
        if (left < right) {
            int pivot = partition(arr, left, right, d);
            quicksort(arr, left, pivot - 1, d);
            quicksort(arr, pivot + 1, right, d);
        }
    }

    int partition(vector<int>& arr, int left, int right, data& d) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            d.count_of_compare++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                d.count_of_assign += 3; // Incrementing by 3 due to 3 swap operations
            }
        }

        swap(arr[i + 1], arr[right]);
        d.count_of_assign += 3; // Incrementing by 3 for the final swap operation
        return i + 1;
    }

public:
    fast_sort_rec(vector<int> arr) {
        VEC = arr;
    }

    data sort() override {
        data mydata = data();

        Timer timer;
        quicksort(VEC, 0, int(VEC.size()) - 1, mydata);
        mydata.time += timer.elapsed();
        if (DEBUG) cout << VEC;
        return mydata;
    }
    string name = "Быстрая сортировка рекурсией";
    string get_name() {
        return name;
    }
};
