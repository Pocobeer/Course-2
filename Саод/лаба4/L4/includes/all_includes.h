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

#include "fmt/chrono.h"
#include "fmt/core.h"

#include "timer.h"



using namespace std;

class BASIC_CLASS {
public:
    virtual string get_name() = 0;
    virtual void change_isk(int) = 0;
    virtual int solve() = 0;
    virtual int solve(int) = 0;
    virtual int get_iter() = 0;
    virtual void restruct(vector<int> &__a) = 0;
};


ostream& operator<<(ostream& stream, const vector<vector<int>>& vec) {
    for (auto& a : vec) {
        for (auto& b : a)
            stream << b << " ";
        stream << endl;
    }
    return stream;
}

ostream& operator<<(ostream& stream, const vector<int>& vec) {
    for (auto& a : vec)
        stream << a << " ";
    return stream;
}

int random_int(int left = 0, int right = 1000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(left, right);
    return dist(gen);
}