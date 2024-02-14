﻿#include <iostream>
#include<string>
using namespace std;
class Family {
private:
	string Name, Surname,Fathername;
	int Age;
	string Sex;
	string Status;
public:
	void Print();
	Family(string Surnamev, string Namev, string Fathernamev) {
		Surname = Surnamev;
		Name = Namev;
		Fathername = Fathernamev;
	}
	/*Family(int Agev) {
		Age = Agev;
	}*/
	Family(string Sexv,string Statusv) {
		Sex = Sexv;
		Status = Statusv;
	}
	Family(int Agevv) {
		Age = Agevv;
	}
	void setAge(int Age) {
		this->Age;
	}
	void showage() const {
		cout << "Age: " << Age << endl;
	}
	class Salary {
	private:
		int salary;
	public:
		/*Salary(int salary) {
			this->salary;
		}*/
		int GetSalary() {
			return salary;
		}
		int SetSalary(int salaryv) {
			salary=salaryv;
			return salary;
		}
	};

	void Print1() {
		Salary amount;
		amount.SetSalary(2000);
		cout << "Surname: " << Surname << "\t\tName: " << Name << "\t\tFathername: " 
			<< Fathername << "\nSalary: " ;
		int result = amount.GetSalary();
		cout << result << endl;
	}
	void Print2() {
		cout << "Age: " << Age << endl;
	}
	void Print3() {
		cout << "Sex: " << Sex << "\nStatus: " << Status << endl;
	}
};
/*void Family::Print() {
	cout << "Surname: " << Surname << "\t\tName: " << Name << "\t\tFathername: " 
	<< Fathername << "\nAge: " << Age << "\nSex: " << Sex << "\nStatus: " << Status 
	<< "\nSalary: " << endl;
}*/
class Value {
private:
	const int constValue;
	const int &addValue;
	int &refValue;
public:
	Value(int constvalue, int addvalue, int refvalue) : constValue(constvalue), addValue(addvalue), refValue(refvalue) {};
	void Out() {
		cout << "Sum = " << constValue + addValue + refValue << endl;
	}
};
class Float {
	float value;
public:
	Float(float val) : value(val) {}
	Float() {
		//value = 3.14;
	}
	float Get() {
		return value;
	}
	/*Float(const Float& f) {
		Float = f.value;
	}*/
	Float(const Float& f) :value(f.value) {};
};
class Complex {

public:
	Float Re;
	Float Im;
	Complex(float re, float im) : Re(re), Im(im) {};
	Complex(float Re) {
		this->Re = Re;
	}
	void Out() {
		cout << Re.Get() << "/" << Im.Get() << endl;
	}
	Complex(const Complex& c) : Re(c.Re), Im(c.Im) {
		cout << "Copy constructor" << endl;
	}
	//Complex(const Complex& c);
	Complex& operator = (const Complex& c) {
		Re = c.Re;
		Im = c.Im;
		return *this;
	}

};
class Test_2;
class Test_1 {
	
	int test;
public:
	int num;
	Test_1(int num) {
		this->num = num;

	}
	void fun(Test_2);
	friend istream& operator>>(istream& a_1, Test_1& a) {
		cout << "Enter num: " << endl;
		a_1 >> a.num;
		return a_1;
	}
	friend ostream& operator<<(ostream& b_1, const Test_1& b) {
		b_1 << "Num:" << b.num << endl;
		return b_1;
	}
	/*friend Test_1& operator++(Test_1& tst, int) {
		++tst.num;
		return tst;

	}*/
};
Test_1 operator++(Test_1& tst, int) {
	++tst.num;
	return tst;
}
class Test_2 {
public:
	friend void Test_1::fun(Test_2);
};
class Test_14 {
	
public:
	int* Ext;
	Test_14(int a) {
		Ext = new int[1];
		Ext[0] = a;
		
	}
	~Test_14() {
		delete Ext;
	}
	Test_14& operator=(const Test_14& Other) {
		this->Ext[0] = Other.Ext[0];
	}
};
int main()
{
	Family Me("Ivanov", "Vladimir", "Sergeevich");
	Family Me1(19);
	Family Me2("Male", "Student");
	Me.Print1();
	Me1.Print2();
	Me2.Print3();
	const Family const_Family(19);
	const_Family.showage();
	Value Triple(10, 20, 30);
	Triple.Out();
	Complex Re1(3.15, 4.6);
	Complex Re2 = Re1;
	Re1.Out();
	Re2.Out();
	Complex Re3(2.5);
	Re3.Out();
	Test_1 T_1(10);
	cin >> T_1;
	cout << T_1 << endl;
	Test_14 c1(15);
	Test_14 c2 = c1;
	cout << c1.Ext << "/" << c2.Ext << endl;

}
