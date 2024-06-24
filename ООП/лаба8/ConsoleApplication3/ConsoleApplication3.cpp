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
template <typename T>
class Num {
	T num;
public:
	Num() {};
	Num(T n) : num(n) {};
	void out() {
		cout << num << endl;
	}
};
template<class T1> class S1 {
protected:
	T1 s;
public:
	S1(){};
	S1(T1);
	virtual void Out();
	friend ostream& operator<< <>(ostream&, const S1<T1>&);
};
template <class T1> S1<T1>::S1(T1 b) :s(b) {};
template<class T1> void S1<T1>::Out() {
	cout << s << endl;
}
template<class T1> ostream& operator <<(ostream& t, const S1<T1>& sn) {
	t << "Elemenr(1): " << sn.s << endl;
	return t;
}
template<class T2, class T3> class S2 : public S1<T2> {
	T3 dim;
public:
	S2() {};
	S2(T2, T3);
	void Out();
	friend ostream& operator<< <>(ostream&, const S2<T2,T3>&);
};
template <class T2, class T3> S2<T2, T3>::S2(T2 b, T3 d) :S1<T2>(b) {
	dim = d;
}
template <class T2, class T3> void S2<T2, T3>::Out() {
	S1<T2>::Out();
	cout << dim << endl;
}
template<class T2, class T3>ostream& operator <<(ostream& t, const S2<T2, T3>& sdn) {
	t << "Elements(2): " << sdn.s << " " << sdn.dim << endl;
	return t;
}
int main(){
	List1 <int> a;
	a.Push(10);
	a.Push(20);
	a.Push(30);
	a.Push(40);
	a.Out();
	cout << endl;
	a.Del();
	a.Out();
	a.Search(20);
	Num <int> n(2);
	n.out();
	S1<int> nn(19);
	S2<int, double> nn2(24, 3.13);
	nn.Out();
	nn2.Out();
	nn2.S1<int>::Out();
	S1<int>* ptr_S1 = &nn2;
	ptr_S1->Out();
	cout << nn << endl;
	cout << nn2 << endl;
}