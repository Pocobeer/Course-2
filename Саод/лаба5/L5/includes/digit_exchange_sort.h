#pragma once
#include "all_includes.h"

class radix_sort : public BASIC_CLASS {
private:
    vector<int> VEC;
    int max(vector<int>& b) {
        int temp = b[0];
        for (auto& a : b) {
            if (a > temp) {
                temp = a;
            }
        }
        return temp;
    }
public:
    string name = "ײטפנמגמי מבלום";
    radix_sort(std::vector<int>& arr) : VEC(arr) {}
    string get_name() {
        return name;
    }
    data sort() override {
        data mydata = data();
        Timer timer;

        int n = static_cast<int>(VEC.size());
        const int radix = 10;
        int exp = 1;

        int max_val = max(VEC);

        while (max_val / exp > 0) {
            vector<int> output(n);
            vector<int> count(radix, 0);

            for (int i = 0; i < n; i++)
                count[(VEC[i] / exp) % radix]++;

            for (int i = 1; i < radix; i++)
                count[i] += count[i - 1];

            for (int i = n - 1; i >= 0; i--) {
                output[count[(VEC[i] / exp) % radix] - 1] = VEC[i];
                mydata.count_of_assign++;
                count[(VEC[i] / exp) % radix]--;
            }

            for (int i = 0; i < n; i++) {
                VEC[i] = output[i];
                mydata.count_of_assign+=1;
            }

            exp *= radix;
        }

        mydata.time += timer.elapsed();
        return mydata;
    }
};