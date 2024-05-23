#include<iostream>
using namespace std;
template <class T> class List {
protected:
	int top;
	T st[100];
public:
	List() {
		top = -1;
	}
	void Push(T);
	T Pop();
	void Out();
	void Del();
};
template <class T> void List <T>::Out() {
	for(int i=0; i<=top; i++) {
		cout << "Element:" << st[i] << " " << endl;
	}
}
template<typename T> void List<T>::Push(T var) {
	st[++top] = var;
}
template<typename T> T List<T>::Pop() {
	return st[top--];
}
template<typename T> void List<T>::Del() {
	st[top] = 0;
	top--;
}

int main() {
	List <int> a;
	a.Push(10);
	a.Push(20);
	a.Push(30);
	a.Push(40);
	a.Out();
	cout << endl << a.Pop() << endl;
	a.Del();
	a.Out();
}