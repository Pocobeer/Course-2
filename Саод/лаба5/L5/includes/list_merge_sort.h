#pragma once
#include "all_includes.h"

class merge_sort : public BASIC_CLASS {
private:
    vector<int> arr;

    void merge(std::vector<int>& input, int left, int mid, int right, data& d) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(input.begin() + left, input.begin() + left + n1);
        vector<int> R(input.begin() + mid + 1, input.begin() + mid + 1 + n2);

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            d.count_of_compare++;
            if (L[i] <= R[j]) {
                input[k++] = L[i++];
            }
            else {
                input[k++] = R[j++];
            }
            d.count_of_assign++;
        }
        while (i < n1) {
            input[k++] = L[i++];
            d.count_of_assign++;
        }
        while (j < n2) {
            input[k++] = R[j++];
            d.count_of_assign++;
        }
    }

    void mergeSort(vector<int>& input, int left, int right, data& d) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(input, left, mid, d);
            mergeSort(input, mid + 1, right, d);

            merge(input, left, mid, right, d);
        }
    }

public:
    merge_sort(vector<int>& input) : arr(input) {}
    string name = "Сортировка списками";
    string get_name() {
        return name;
    }
    data sort() override {
        data mydata = data();
        Timer timer;
        mergeSort(arr, 0, arr.size() - 1, mydata);
        mydata.time += timer.elapsed();
        return mydata;
    }
};
