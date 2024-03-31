#pragma once

#include "all_includes.h"

class TESTS {
private:
	struct __DATA {
		string name = "";
		int search_res = 0;
		int UP = 0;
		int BP = 0;
		float time = 0;
	};

	vector<BASIC_CLASS*> __VEC_OF_CLASSES {};
	vector<int> VEC;
	vector<int> __VEC_OF_RAND;
	size_t __VEC_SIZE = 0;
	int __TESTS_COUNT = 0;
	vector<__DATA> __VEC_OF_DATA;
	
	vector<thread> __THREADS;

	void __fill_rand() {
		int temp_r = 0;
		for (int i = 0; i <= __TESTS_COUNT; i++) {
			temp_r = random_int(0, __VEC_SIZE - 1);
			__VEC_OF_RAND.push_back(temp_r);
			__VEC_OF_RAND.push_back(temp_r + 1);
		}
	}

	void run_tests(BASIC_CLASS* test) {
		__DATA temp_data{test->get_name(), 0,0,0,0};
		
		for (auto& rand_ : __VEC_OF_RAND) {
			Timer timer;
			int temp_res = test->solve(rand_);
			temp_data.time += timer.elapsed();

			temp_data.search_res = temp_res;
			int temp_iter = test->get_iter();
			if (temp_res == -1) {
				temp_data.BP += temp_iter;
			}
			else {
				temp_data.UP += temp_iter;
			}
		}
		__VEC_OF_DATA.push_back(temp_data);
	}

	void print_data() {
		using namespace fmt;
		print("{:^26}|{:^7}|{:^7}|{:^12}|\n", "ИМЯ", "УП", "БП", "ВРЕМЯ");
		for (auto& a : __VEC_OF_DATA) {
			print("{:^26}|{:^7}|{:^7}|{:^.10f}|\n", a.name, static_cast<long int>(a.UP)*2 / __TESTS_COUNT, static_cast<long int>(a.BP)*2 / __TESTS_COUNT, a.time);
			//print("{:^26}|{:^7}|{:^7}|{:^.10f}|\n", a.name, static_cast<long long int>((a.UP) / (__TESTS_COUNT)), static_cast<long long int>((a.BP) / (__TESTS_COUNT)), a.time);
		}
	}

public:
	TESTS(){}
	TESTS(int &T_C, vector<int> &S_V, vector<BASIC_CLASS*> &CLASSES): __TESTS_COUNT(T_C), VEC(S_V), __VEC_OF_CLASSES(CLASSES) {
		__VEC_SIZE = S_V.size();

		__fill_rand();

		for (auto& basic_classes : __VEC_OF_CLASSES) {
			__THREADS.push_back(thread([&]() {
				run_tests(basic_classes);
			}));
		}
		for (auto& threads : __THREADS) {
			threads.join();
		}
		print_data();
	}
};