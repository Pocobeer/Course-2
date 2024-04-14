#pragma once
#include "all_includes.h"

class two_way_merge : public BASIC_CLASS {
private:
    vector<int> VEC;

    void merge(vector<int>& arr, int const left, int const mid, int const right, data& d) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        vector<int>  leftArray(arr.begin() + left, arr.begin() + left + subArrayOne);
        vector<int> rightArray(arr.begin() + mid + 1, arr.begin() + mid + 1 + subArrayTwo);

        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            d.count_of_compare++;
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void mergeSort(std::vector<int>& arr, int const begin, int const end, data& d) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid, d);
        mergeSort(arr, mid + 1, end, d);
        merge(arr, begin, mid, end, d);
    }

public:
    two_way_merge(std::vector<int>& arr) : VEC(arr) {}
    string name = "Двухпутевая вставка";
    string get_name() {
        return name;
    }
    data sort() override {
        data mydata = data();
        Timer timer;
        mergeSort(VEC, 0, VEC.size() - 1, mydata);

        mydata.time += timer.elapsed();

        return mydata;
    }
};