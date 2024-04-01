#include <iostream>
#include<string>
using namespace std;
class Student {
	const char *Name;
	const char *Surname;
	int Age;
	int* data;
public:
	Student() {
		data = new int;
	}
	Student(const char *name,const char *surname, int age, int a) {
		Name = name;
		Surname = surname;
		Age = age;
		data= new int(a);
	}
	~Student() = default;
	Student(const Student& stud) : Name(stud.Name), Surname(stud.Surname), Age(stud.Age), data(new int(*stud.data)) {};
	/*void Out() {
		cout << "Name: " << Name << "\nSurname: " << Surname << "\nAge: " << Age << endl;
	}*/
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
	Out(Ve,sal);
}