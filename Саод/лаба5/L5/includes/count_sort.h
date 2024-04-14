#pragma once
#include "all_includes.h"

class count_sort : public BASIC_CLASS {
private:
    vector<int> VEC = {};
public:
    string name = "Сортировка пересчитыванием";
    string get_name() {
        return name;
    }
    count_sort(vector<int>& arr): VEC(arr) {}
    data sort() {
        data mydata = data();
        Timer timer;

        int N = VEC.size();

        int M = 0;

        for (int i = 0; i < N; i++)
            M = max(M, VEC[i]);

        vector<int> countArray(M + 1, 0);

        for (int i = 0; i < N; i++)
            countArray[VEC[i]]++;

        for (int i = 1; i <= M; i++)
            countArray[i] += countArray[i - 1];

        vector<int> outputArray(N);

        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[VEC[i]] - 1] = VEC[i];
            mydata.count_of_assign++;
            countArray[VEC[i]]--;
        }

        mydata.time += timer.elapsed();
        return mydata;
    }
};
