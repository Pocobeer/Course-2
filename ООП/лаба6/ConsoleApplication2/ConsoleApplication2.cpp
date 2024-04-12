#include <iostream>
#include<string>
using namespace std;
class Student {
	const char *Name;
	const char *Surname;
	int Age;
	int* data;
	int size;
	int* p;
public:
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
	/*Student operator ++(int) {
		Age++;
		return *this;
	}*/
	Student& operator++( int) {
		Student Age_timed = *this;
		(*this)++;
		return Age_timed;
	}
	Student operator +(const Student& st) {
		return this->Age + st.Age;
	}
	Student& operator=(const Student& st) {
		data = new int;
		data = st.data;
		return *this;
	}
	int& operator[](int i) {
		if (i<0 || i > size) {
			cout << "Arrange from massive" << endl;
		}
		return p[i];
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
	void Out_arr() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}
};
class Mass {
	int size;
	int* p;
public:
	explicit Mass(int n = 5);
	Mass(const int arr[], int n) : size(n) {
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = arr[i];
	}
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
};
/*void Out_1(Student::Grant& Val) {
	cout << "Grant: " << Val.Value << endl;
}
void Out(Student& stud) {
	cout << "Name: " << stud.Name << "\nSurname: " << stud.Surname << "\nAge: " << stud.Age << endl;
}*/
void Out(Student& stud, Student::Grant& val) {
	cout << "Name: " << stud.Name << "\nSurname: " << stud.Surname << "\nAge: " << stud.Age << "\nSalary: " << val.Value << endl;
}
int main() {
	Student Ve("Vladimir", "Ivanov", 17, 22);
	Student::Grant sal(2000);
	Student Ve_1 = Ve;
	Out(Ve,sal);
	Out(Ve_1, sal);
	Student Ve_2(19);
	int arr_int[8] = { 1,2,3,4,5,6,7,8 };
	Mass arr(arr_int, 8);
	arr.Out_arr();
	cout << arr[1] << endl;
	cout << arr[9] << endl;
}