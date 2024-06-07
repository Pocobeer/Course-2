﻿#include<iostream>
#include<string>
#include<deque>
#include<list>
#include<stack>
#include<algorithm>
#include<vector>
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
	for(int i=0; i<=top; i++) {
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
template<typename T, typename n> struct Symbol {
protected:
	T value;
	n number;

public:
	Symbol() {};
	Symbol(char ch, int n) : value(ch), number(n) {};
	friend void out(const Symbol <T, int> & sym);
};
template <typename T, int max_lenght = 15> struct String : public Symbol <T,int> {
	T data[max_lenght];
	int lenght;
public:
	String() {};
	String(T, int);
	void out();
};
template <class T, int max_lenght> String <T, max_lenght>::String(T var, int max_lenght) {
	lenght = max_lenght;
}
template <class T, int max_lenght> void out(const Symbol <T, int> & sym) {
	using Symbol <T, int>::out();
	this->Symbol <T, int>::out();
	cout << sym.data << endl;
}
class Person {
public:
	string Name;
	int Age;
	double Salary;
	Person(string Name, int age, double salary) : Name(Name), Age(age), Salary(salary) {};
};
class Student {
public:
	string Name;
	int Age;
	int Marks;
	Student(string Name, int age, int marks) :Name(Name), Age(age), Marks(marks) {};
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
	Symbol <char, int> b('v', 11);
	String <char, 10> c('v', 10);
	c.out();
	Symbol <char, int> *d = &c;
	out(b);
	out(c);
	out(*d);
	return 0;
	list <int> v={ 10, 20,20, 30, 40 };
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
	vector <Person> person = { {"Vall", 20, 1000.0}, {"Val", 21, 2000.0}, {"Va", 22, 3000.0} };
	vector <Student> student = { {"V234", 20, 4}, {"Vafwel", 21, 3}, {"Vall", 22, 5} };
	auto f1 = search(person.begin(), person.end(),student.begin(), student.end(),
		[](const Person& pe, const Student& st) {
			return pe.Name == st.Name; });
	int count_4 = count_if(person.begin(), person.end(), [](const Student& st) {
		return st.Marks == 4; });
	int count_5 = count_if(person.begin(), person.end(), [](const Student& st) {
		return st.Marks == 5; });
	vector <int> ex_8_1 = { 1,2,3,4,5,6 };
	vector <int> ex_8_2 = { 7,8,9,13,14 };
	vector <int> ex_8;
	merge(ex_8_1.begin(), ex_8_1.end(), ex_8_2.begin(), ex_8_2.end(), ex_8);
	for (int i = 0; i < ex_8.size(); i++) {
		cout << ex_8[i] << " ";
	}

}