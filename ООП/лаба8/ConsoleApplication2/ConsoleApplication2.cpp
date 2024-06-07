#include<iostream>
#include<string>
#include<deque>
#include<list>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
template <class T> class List1 {
protected:
	int top;
	T st[100];
public:
	List1() {
		top = -1;
	}
	void Push(T);
	T Pop();
	void Out();
	void Del();
	void Search(T);
};
template <class T> void List1 <T>::Out() {
	for (int i = 0; i <= top; i++) {
		cout << "Element:" << st[i] << " " << endl;
	}
}
template<typename T> void List1<T>::Push(T var) {
	st[++top] = var;
}
template<typename T> T List1<T>::Pop() {
	return st[top--];
}
template<typename T> void List1<T>::Del() {
	if (top >= 0) {
		for (int i = 0; i < top; i++) {
			st[i] = st[i + 1];
		}
		top--;
	}
}
template<typename T> void List1<T>::Search(T var) {
	bool found = false;
	for (int i = 0; i <= top; i++) {
		if (st[i] == var) {
			found = true;
		}
		else {
			continue;
		}
	}
	if (found == true) {
		cout << var << " Found" << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
}

int numnum(int num) {
	return num * num;
}
class Ex_11 {
public:
	int id;
	string nam;
	Ex_11(int id, string nam) : id(id), nam(nam) {};
};
int main() {
	List1 <int> a;
	a.Push(10);
	a.Push(20);
	a.Push(30);
	a.Push(40);
	a.Out();
	cout << endl << a.Pop() << endl;
	//a.Del();
	a.Out();
	a.Search(20);
	list <int> v = {10, 20,20, 30, 40};
	auto f_list = find(v.begin(), v.end(), 20);
	int f_count = count(v.begin(), v.end(), 20);
	deque <int> s = { 10, 20,20, 30, 40 };
	int s_count = count(s.begin(), s.end(), 20);
	auto f_deq = find(s.begin(), s.end(), 20);
	stack <int> t;
	t.push(10);
	t.push(20);
	t.push(20);
	t.push(30);
	t.push(40);
	stack <int> u;
	int u_count = 0;
	bool found = false;
	while (!t.empty()) {
		if (t.top() == 20) {
			found = true;
			u_count++;
		}
		u.push(t.top());
		t.pop();
	}
	if (found == true) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	
	vector <int> ex_8_1 = { 1,2,3,4,5,6 };
	vector <int> ex_8_2 = { 7,8,9,13,14 };
	vector <int> ex_8(ex_8_1.size() + ex_8_2.size());
	merge(ex_8_1.begin(), ex_8_1.end(), ex_8_2.begin(), ex_8_2.end(), ex_8.begin());
	for (int i = 0; i < ex_8.size(); i++) {
		cout << ex_8[i] << " ";
	}
	cout << endl;
	
	list <int> ex_9_1 = { 1,2,3,4 };
	list <int > ex_9_1_1(ex_9_1.size());
	function<int(int)> nn2 = numnum;
	transform(ex_9_1.begin(), ex_9_1.end(), ex_9_1_1.begin(), nn2);
	for (int nnum : ex_9_1_1) {
		cout << nnum << " ";
	}
	cout << endl;
	deque <int> ex_9_2 = { 5,6,7,8 };
	deque <int> ex_9_2_1(ex_9_2.size());
	transform(ex_9_2.begin(), ex_9_2.end(), ex_9_2_1.begin(), nn2);
	for (int nnum : ex_9_2_1) {
		cout << nnum << " ";
	}
	vector <int> ex_11 = { 3,4,5,6,1,2,54 };
	auto iter_1{ ex_11.begin() };
	cout << *iter_1 << endl;
	*iter_1 = 100;
	cout << ex_11[0] << endl;
	queue <int> ex_11_2 ;
	ex_11_2.push(10);
	ex_11_2.push(20);
	ex_11_2.push(30);
	ex_11_2.push(40);
	ex_11_2.push(50);
	ex_11_2.push(60);
	queue <int> it_ex_11_2;
	while (!it_ex_11_2.empty()) {
		cout << it_ex_11_2.front() << " ";
		it_ex_11_2.pop();
	}
	vector <Ex_11> objve;
	Ex_11 obj_1(1, "Vall");
	objve.push_back(obj_1);
	queue <Ex_11> objqu;
	for (int i = 0; i < objve.size(); i++) {
		objqu.push(objve[i]);
	}
	while (!objqu.empty()) {
		Ex_11 obj = objqu.front();
		cout << obj.id << " " << obj.nam << endl;
		objqu.pop();
	}
	list <Ex_11> objli;
	Ex_11 obj_2(2, "Val");
	objli.push_back(obj_1);
	objli.push_back(obj_2);
	list<Ex_11>::reverse_iterator rit;
	for (rit = objli.rbegin(); rit != objli.rend(); rit++) {
		cout << rit->id << " " << rit->nam << endl;
	}
	return 0;
}