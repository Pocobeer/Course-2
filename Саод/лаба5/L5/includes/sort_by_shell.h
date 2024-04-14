#pragma once
#include "all_includes.h"


class shell_sort : public BASIC_CLASS {
private:
	vector<int> VEC = {};
	data my_data = data{ (0,0,0) };
public:
	shell_sort(vector<int> arr) {
		VEC = arr;
	}
	data sort() override {
		Timer timer;
		for (size_t d = VEC.size() / 2; d > 0; d /= 2) {
			for (size_t i = d; i < VEC.size(); i++) {
				my_data.count_of_compare++;
				for (int j = i - d; j >= 0 && VEC[j] > VEC[j + d]; j -= d) {
					my_data.count_of_assign++;
					swap(VEC[j], VEC[j + d]);
				}
			}
		}
		my_data.time += timer.elapsed();
		return my_data;
	}
	string name = "Сортировка Шелла";
	string get_name() {
		return name;
	}
};