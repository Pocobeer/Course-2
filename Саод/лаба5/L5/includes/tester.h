#pragma once
#include "all_includes.h"

class TESTER_class {
private:

	struct __data {
		string name;
		BASIC_CLASS::data mydata = {0,0,0};
	};
	vector<__data> ALL_RESULTS = {};
	vector<BASIC_CLASS*> VEC_OF_BASIC_CLASS = {};
	const unsigned int TESTS_COUNT;
	vector<unsigned int> VEC_LEN;

	vector<thread> __THREADS;

	void print_res() {
		cout << setw(30) << left << "Имя" << "|" << " Число сравнений " << "|" << " Число приравниваний " << "|" << " Время\n";
		for (auto& test : ALL_RESULTS) {
			cout << setw(30) << left << test.name << "| " << setw(15) << left << test.mydata.count_of_compare/TESTS_COUNT \
			<< " | " << setw(19) << left << test.mydata.count_of_assign / TESTS_COUNT << " | " << fixed <<test.mydata.time << endl;
		}
	}

	void run_tests(BASIC_CLASS* test) {
		for (int i = 0; i < TESTS_COUNT; i++) {
			for (auto& res : ALL_RESULTS) {
				if (res.name == test->get_name()) {
					auto temp = test->sort();
					res.mydata += temp;
				}
			}
		}
	}
	void run_tests() {
		for (auto& test : VEC_OF_BASIC_CLASS) {
			for (int i = 0; i < TESTS_COUNT; i++) {
				for (auto& res : ALL_RESULTS) {
					if (res.name == test->get_name()) {
						auto temp = test->sort();
						res.mydata += temp;
					}
				}
			}
		}
		print_res();
	}

public:
	TESTER_class(vector<BASIC_CLASS*>& BC, const int &TC): VEC_OF_BASIC_CLASS(BC), TESTS_COUNT(TC) {
		for (auto& a : VEC_OF_BASIC_CLASS) {
			ALL_RESULTS.push_back({a->get_name()});
		}
		//run_tests();
		for (auto& basic_classes : VEC_OF_BASIC_CLASS) {
			__THREADS.push_back(thread([&]() {
				run_tests(basic_classes);
			}));
		}
		for (auto& threads : __THREADS) {
			threads.join();
		}
		print_res();
	}
};
// TO DO
// измени mydata, чтобы там хранилось имя