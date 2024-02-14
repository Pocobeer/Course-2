#include <iostream>
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
	Complex() {}
	Complex* operator->() {
		cout << "Operator" << endl;
		return this;
	}
	void Out_1() {
		cout << Re.Get() << "/" << Im.Get() << endl;
	}
	void Out_2() {
		cout << Re.Get() << endl;
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
	void* operator new(size_t size) {
		cout << "New operation for class Complex, bytes need: " << size << endl;
		void* storage = malloc(size);
		if (NULL == storage) {
			cout << "Lack of memory" << endl;
		}
		return storage;
	}
	void operator delete(void* p) {
		cout << "Operation delete for class Complex" << endl;
		free(p);
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
class Ex_15 {
	int size;
	int* p;
public:
	explicit Ex_15(int n = 5);
	Ex_15(const int arr[], int n) :size(n) {
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = arr[i];
		}
	}
	~Ex_15() {
		delete[]p;
	}
	int& operator[](int i) {
		if (i<1 || i>size) {
			cout << "Out of array" << endl;
			exit(0);
		}
		return p[i];
	}
	void Out() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
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
	Re1.Out_1();
	Re2.Out_1();
	Complex Re3(2.5);
	Re3.Out_2();
	Test_1 T_1(10);
	//cin >> T_1;
	cout << T_1 << endl;
	Test_14 c1(15);
	Test_14 c2 = c1;
	cout << *c1.Ext << "/" << *c2.Ext << endl;
	int array_15[10] = { 1,2,3,4,5 };
	Ex_15 arr(array_15, 10);
	arr.Out();
	cout << arr[1] << endl;
	//cout << arr[19] << endl;
	float re_1 = 2.6, re_2 = 5.2;
	Complex Ex_16(re_1, re_2);
	//(Ex_16.operator->())->Out();
	//Ex_16->Out();
	//cout << Ex_16->Im << "/" << Ex_16->Re << endl;
	Complex *complex_17_1 = new Complex(10.8);
	//complex_17_1->Out_2();
	//Complex *complex_17_2 = ::new Complex(24.3);
	//complex_17_2->Out_2();
	//delete complex_17_1;
	//::delete complex_17_2;
}
