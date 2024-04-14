#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <algorithm>
#include <thread>
#include <iomanip>
#include <fstream>
#include <chrono>


using namespace std;

class Timer {
public:
	Timer() : start(std::chrono::high_resolution_clock::now()) {}
	float elapsed() {
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		return duration.count();
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

class BASIC_CLASS {
public:
	virtual struct data {
		unsigned int count_of_compare = 0;
		unsigned int count_of_assign = 0;
		float time = 0;
		friend ostream& operator<<(ostream& stream, const data& data_) {
			cout << setw(28) << left << "Количество сравнений: "	 << data_.count_of_compare << endl;
			cout << setw(28) << left << "Количество приравниваний: " << data_.count_of_compare << endl;
			cout << setw(28) << left << "Время: " << fixed			 << data_.time << endl;
			return stream;
		}
		data& operator+=(const data& other) {
			this->count_of_compare += other.count_of_compare;
			this->count_of_assign  += other.count_of_assign;
			this->time += other.time;
			return *this;
		}
	};
	bool DEBUG = false;
	virtual string get_name() = 0;
	virtual data sort() = 0;
};

template <typename T>
T vec_max(vector<T>& vec) {
	int max = vec[0];
	for (auto& a : vec) {
		if (a > max) {
			max = a;
		}
	}
	return max;
}

template <typename T>
void show_vector_as_py(vector<T>& vec) {
	int max = to_string(vec_max(vec)).size();
	unsigned int temp = 0;
	cout << "{ ";
	for (auto& a : vec) {
		if (temp % 10 == 0) cout << endl;
		cout << " [" << setw(max) << a << "] ";
		temp++;
		cout << " ";
	}
	cout << "}\n";
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<vector<T>>& vec) {
    for (auto& a : vec) {
        for (auto& b : a)
            stream << b << " ";
        stream << endl;
    }
    return stream;
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec) {
    for (auto& a : vec)
        stream << a << " ";
    return stream;
}

int random_int(int left = 0, int right = 999) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(left, right);
    return dist(gen);
}