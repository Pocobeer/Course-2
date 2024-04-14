#pragma once
#include "all_includes.h"

class heap_sort : public BASIC_CLASS {
private:
    vector<int> VEC = {};

    void heapify(std::vector<int>& arr, int n, int i, data& d) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        d.count_of_compare += 2; // Increment by 2 for the comparisons in the if condition
        if (left < n && arr[left] > arr[largest])
            largest = left;

        d.count_of_compare += 2; // Increment by 2 for the comparisons in the if condition
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            d.count_of_assign += 3; // Increment by 3 for the swap operation
            heapify(arr, n, largest, d);
        }
    }

public:
    heap_sort(std::vector<int>& arr) : VEC(arr) {}
    string name = "Пирамидальная сортировка";
    string get_name() {
        return name;
    }
    data sort() override {
        data mydata = data();
        Timer timer;
        int n = static_cast<int>(VEC.size());

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(VEC, n, i, mydata);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(VEC[0], VEC[i]);
            mydata.count_of_assign += 3; // Increment by 3 for the swap operation

            heapify(VEC, i, 0, mydata);
        }

        mydata.time += timer.elapsed();
        if (DEBUG) cout << VEC << endl;
        return mydata;
    }
};