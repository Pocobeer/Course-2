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
	Family(string Surnamev, string Namev, string Fathernamev, int Agev, string Sexv, string Statusv ) {
		Surname = Surnamev;
		Name = Namev;
		Fathername = Fathernamev;
		Age = Agev;
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
			<< Fathername << "\nAge: " << Age << "\nSex: " << Sex << "\nStatus: " << Status 
			<< "\nSalary: " ;
		int result = amount.GetSalary();
		cout << result << endl;
	}

};
/*void Family::Print() {
	cout << "Surname: " << Surname << "\t\tName: " << Name << "\t\tFathername: " << Fathername << "\nAge: " << Age << "\nSex: " << Sex << "\nStatus: " << Status << "\nSalary: " << endl;
}*/
int main()
{
	Family Me( "Ivanov", "Vladimir", "Sergeevich", 19, "Male", "Student");
	Me.Print1();
	const Family const_Family(19);
	const_Family.showage();
}
