#include<iostream>
#include<string>
using namespace std;
class Word {
	string word;
	int first, second;
public:
	Word(int f, int s) :first(f), second(s) {};
	Word(string w) :word(w) {};
	int Get() {
		cout << "Object address:" << this << " ";
		return first;
		cout << endl;
	}
	friend void showWord(Word& w);
	void inputWord() {
		cout << "Enter word: ";
		cin >> word;
	}
	static int co;
	static int Get_Count() {
		return co;
	}
	
	~Word() = default;
};
void showWord(Word& w) {
	cout << "Friend void " << w.word << endl;

}
int Word::co = 20;
class WordCount : public Word {
	int wordCount;
	//long tt;
public:
	WordCount(int f, int s) :Word(f, s) {};
	WordCount(string w) :Word(w) {
		wordCount = 1;
		for (int i = 0; i < w.length(); i++) {
			if (w[i] == ' ') {
				wordCount++;
			}
		}
	}
	void showWordCount() {
		showWord(*this);
		cout << wordCount << endl;
	}
	static void Set_Count() {
		co = 0;
	}
	~WordCount()=default;
};
class Test_3 :public Word {
	//char tst;
public:
	Test_3(int f, int s) :Word(f, s) {};
};
class All :public WordCount, public Test_3 {
public:
	All(int f, int s, int t, int u):WordCount(f, s), Test_3(t, u) {};
};
All a(1, 2, 3, 4);
class Pupupu {
public:
	virtual void show() = 0;
};
class Human: public Pupupu {
	string name;
	string surname;
	int age;
public:
	Human() {};
	Human(string n, string s, int a) :name(n), surname(s), age(a) {};
	void show() {
		cout << "Human:" << name << " " << surname << " " << age << endl;
	}
};
class Employee :public Human {
	string speciality;
public:
	Employee() {};
	Employee(string n, string s, int a, string sp) :Human(n, s, a) {
		speciality = sp;
	}
	void show() {
		cout << "Employee:" << speciality << endl;
	}
};
class Student :public Employee {
	string group;
	float avg_mark;
public:
	Student() {};
	Student(string n, string s, int a, string g, float m) :Employee(n, s, a, g) {
		group = g;
		avg_mark = m;
	}
	void show() {
		cout << "Student:" << group << " " << avg_mark << endl;
	}
};

class A {
	int a;
public:
	A() = default;
	A(int a) :a(a) {};
	virtual int Get() {
		return a;
	}
};
class B : public A
{
	int b;
public:
	B() = default;
	B(int b) :b(b) {};
	int Get() {
		return b;
	}
};


int main() {
	Word w_1("Pupupu");
	showWord(w_1);
	cout << "type of class:" << typeid(w_1).name() << endl;
	WordCount w_2("Pupupupu pupupu");
	cout << "type of class:" << typeid(w_1).name() << endl;
	w_2.showWordCount();
	cout << "type of class:" << typeid(w_2).name() << endl;
	cout << "static field:" << w_1.Get_Count() << endl;
	w_2.Set_Count();
	cout << "static field:" << w_2.Get_Count() << endl;
	cout << "value of field:" << a.WordCount::Get() << endl;
	cout << "value of field:" << a.Test_3::Get() << endl;
	Human* h_1 = new Human;
	Employee* emp_1 = new Employee();
	Student* st_1 = new Student();
	Employee emp("Vladimir","Ivanov", 19, "IT");
	h_1=&emp;
	h_1->show();
	Student st("Vladimir","Ivanov", 19, "IT-21", 5.5);
	h_1=&st;
	h_1->show();
	h_1 = dynamic_cast<Employee*>(h_1);
	h_1->show();
	h_1 = dynamic_cast<Student*>(h_1);
	h_1->show();
	Employee emp;
	Employee& emp_ref = emp;
	Human& h_ref = emp;
	
	//Employee& emp_ref = dynamic_cast<Employee&>(h_ref);
	//emp_ref.show();
	B bb;
	B& bb_ref = bb;
	A& A_ref = bb;
	dynamic_cast<B&>(A_ref).Get();
}