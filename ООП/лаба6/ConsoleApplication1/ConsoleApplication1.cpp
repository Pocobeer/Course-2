#include <iostream>
using namespace std;
class Family {
public:
	void Set_Name(string name) {
		this->Name = name;
	}
	void Set_Surname()
private:
	string Name;
	string Surname;
	string Otchestvo;
	int Age;
	int Sex;
	int Status;

};
int main()
{
	Family Dad;
	Dad.Set_Name("Sergey");


}
