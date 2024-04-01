#pragma once
#include "all_includes.h"

class has_search : public BASIC_CLASS {
private:
	vector<pair<string, unsigned long int>> VEC;
	string ISKOMOE = "";
	string NAME = "Поиск с хешированием";

	int hash(string& in) {
		unsigned long int HASH = 0;
		for (auto& i : in) {
			if (i < 10)	i = (i+1) * 18031;
			HASH = HASH * (10) + static_cast<int>(i) * 91023 + 10241 + (static_cast<int>(i) * 1000) % 46;
		}
		return HASH;
	}
	int ITER_COUNT = 0;
public:
	string get_name() {
		return NAME;
	}
	void change_isk(int isk_) {
		ISKOMOE = to_string(isk_);
	}
	has_search(vector<string>& a) {
		for (int i = 0; i < a.size() - 1; i++) {
			VEC.push_back({ a[i], hash(a[i]) });
			if (i == a.size() - 1) {
				sort(VEC.begin(), VEC.end(), [](auto& left, auto& right) {
					return left.second < right.second;
				});
			}
		}
	}
	has_search(){}
	has_search(vector<int>& a) {
		vector<string> a_;
		for (const auto& b : a) {
			a_.push_back(to_string(b));
		}
		for (int i = 0; i < a_.size() - 1; i++) {
			VEC.push_back({ a_[i], hash(a_[i]) });
			if (i == a.size() - 2) {
				sort(VEC.begin(), VEC.end(), [](auto& left, auto& right) {
					return left.second < right.second;
				});
			}
		}
	}
	int solve() {
		auto temp_h = hash(ISKOMOE);
		int l = 0, r = VEC.size() - 1;

		while (r > l) {
			ITER_COUNT++;
			int m = (l + r) / 2;

			if (VEC[m].second < temp_h) {
				l = m + 1;
			}
			else if (VEC[m].second > temp_h) {
				r = m - 1;
			}
			else {
				return VEC[m].second;
			}
		}
		if (VEC[l].second == temp_h) {
			return VEC[l].second;
		}
		else {
			return -1;
		}
	}
	int solve(int isk_) {
		change_isk(isk_);
		return solve();
	}
	int get_iter() {
		int temp_i = ITER_COUNT;
		ITER_COUNT = 0;
		return temp_i;
	}
	void restruct(vector<int>& a) {
		vector<string> a_;
		for (const auto& b : a) {
			a_.push_back(to_string(b));
		}
		for (int i = 0; i < a_.size() - 1; i++) {
			VEC.push_back({ a_[i], hash(a_[i]) });
			if (i == a.size() - 2) {
				sort(VEC.begin(), VEC.end(), [](auto& left, auto& right) {
					return left.second < right.second;
					});
			}
		}
	}
};