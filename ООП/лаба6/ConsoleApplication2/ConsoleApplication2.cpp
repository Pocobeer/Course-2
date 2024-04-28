#include <iostream>
#include<string>
#include<malloc.h>
#include<stddef.h>
using namespace std;
class Student {
	const char *Name;
	const char *Surname;
	
	int* data;
public:
	int Age;
	//explicit Student(int n = 5);
	Student() {
		data = new int;
		//p = new int;
	}
	Student(const char* name, const char* surname, int age, int a) {
		Name = name;
		Surname = surname;
		Age = age;
		data= new int(a);
	}
	Student(int Age) {
		this->Age = Age;
		cout << Age << endl;
	}
	/*Student(const int arr[], int n) : size(n) {
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = arr[i];
	}*/
	Student(const Student& stud) : Name(stud.Name), Surname(stud.Surname), Age(stud.Age), data(new int(*stud.data))/*, size(stud.size), p(new int(*stud.p))*/ {};
	//Student(const Student& st) : size(st.size), p(new int(*st.p)) {}
	/*void Out() {
		cout << "Name: " << Name << "\nSurname: " << Surname << "\nAge: " << Age << endl;
	}*/
	~Student() = default;
	/*~Student() {
		delete data;
		delete []p;
	}*/
	Student& operator ++() {
		++Age;
		return *this;
	}
	/*Student operator++(int) {
		Student temp(*this);
		Age++;
		return temp;
	}*/
	/*Student& operator++(int) {
		Student Age_timed = *this;
		(*this)++;
		return Age_timed;
	}*/
	Student operator +(const Student& st) {
		return this->Age + st.Age;
	}
	Student& operator=(const Student& st) {
		data = new int;
		data = st.data;
		return *this;
	}
	Student* operator ->()
	{
		cout << "-> Operator" << endl;
		return this;
	}
	class Grant {
		
	public:
		int Value;
		Grant(int value) {
			Value = value;
		}
		/*void Out_1() {
			cout << "Value: " << Value << endl;
		}*/
		//friend void Out_1(Student&,Student::Grant&);
	};
	friend void Out(Student&, Student::Grant&);
	void Out_age() {
		cout << "Age: " << Age << endl;
	}
};
/*Student operator++(Student& st, int) {
	st.Age++;
	return st;
}*/
class Mass {
	int size;
	int* p;
	int test;
	
public:
	Mass() {};
	//explicit Mass(int n = 5);
	Mass(const int arr[], int n) : size(n) {
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = arr[i];
	}
	Mass(int tst) :test(tst) {};
	void* operator new(size_t);
	void operator delete(void*);
	
	~Mass() {
		delete[]p;
	}
	
	int& operator[](int i) {
		if (i<0 || i > size) {
			cout << "Arrange from massive" << endl;
			exit(0);
		}
		return p[i];
	}

	void Out_arr() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}
	void Outt() {
		cout << "Nest: " << test << endl;
	}
};
//static void* (*new_ptr)(size_t);
void* Mass::operator new(size_t size_1) {
	cout << "New operation for class mass, byte need: " << size_1 << endl;
	void* storage = malloc(size_1);
	if (NULL == storage) {
		cout << "Lack of memory" << endl;
	}
	return storage;
}
void Mass:: operator delete(void* p) {
	cout << "Delete operation for Mass" << endl;
	free(p);
}
//void* (Mass::*new_ptr)(size_t) = &Mass::operator new;
/*void Out_1(Student::Grant& Val) {
	cout << "Grant: " << Val.Value << endl;
}
void Out(Student& stud) {
	cout << "Name: " << stud.Name << "\nSurname: " << stud.Surname << "\nAge: " << stud.Age << endl;
}*/
void Out(Student& stud, Student::Grant& val) {
	cout << "Name: " << stud.Name << "\nSurname: " << stud.Surname << "\nAge: " << stud.Age << "\nSalary: " << val.Value << endl;
}
void(*ptr_test)(Student& stud, Student::Grant& val) = &Out;
int main() { 
	Student Ve("Vladimir", "Ivanov", 17, 22);
	Student::Grant sal(2000);
	int aged = 23;
	Student age_t(aged);
	++age_t;
	age_t.Out_age();
	Student Ve_1 = Ve;
	Out(Ve,sal);
	Out(Ve_1, sal);
	Student Ve_2(19);
	int arr_int[8] = { 1,2,3,4,5,6,7,8 };
	Mass arr(arr_int, 8);
	arr.Out_arr();
	cout << arr[1] << endl;
	cout << age_t->Age << endl;
	Mass *ptr_test_1 = new Mass(100);
	ptr_test_1->Outt();
	Mass* ptr_test_2 = new Mass(3.14);
	ptr_test_2->Outt();
	delete ptr_test_1;
	delete ptr_test_2;
	(*ptr_test)(Ve_1, sal);
}