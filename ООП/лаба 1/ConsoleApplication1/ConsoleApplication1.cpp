#include <iostream>
using namespace std;
int integer = 2;
char Char = 'C';
wchar_t Wchar = L'A';
bool Bool = true;
float pi = 3.14;
double pi1 = 3.141592;

struct Structure {
	int StructureNumber;
	double StructureFirstChar;
	int StructureElement;
}Structure;
int main() {
	setlocale(0,"");
	cout << "1 Пункт:" << endl;
	cout << "число байт, необходимых для  хранения целого типа данных (int) : " << sizeof(integer) << endl;
	cout << "число байт, необходимых для  хранения символьного типа данных (char) : " << sizeof(Char) << endl;
	cout << "число байт, необходимых для  хранения расширенного символьного типа данных (wchar_t) : " << sizeof(Wchar) << endl;
	cout << "число байт, необходимых для  хранения логического типа данных типа данных (bool) : " << sizeof(Bool) << endl;
	cout << "число байт, необходимых для  хранения целого типа данных (float) : " << sizeof(pi) << endl;
	cout << "число байт, необходимых для  хранения целого типа данных (double) : " << sizeof(pi1) << endl;
	cout << "число байт, необходимых для  структуры с тремя полями (struct) : " << sizeof(Structure) << endl;
	cout << "2 Пункт:" << endl;
	typedef unsigned long ULONG;
	ULONG  A = 3896893782;
	cout << "3 Пункт:" << endl;
	enum Human1;
	enum Human{Australian, Russian = 2, French};
	Human human = Russian;
	if (human == Russian) {
		cout << "Human is Russian" << endl;
	}
	cout << "Число байт, требуемое для хранения: " << sizeof(Human) << endl;
	cout << "4 Пункт:" << endl;
	cout << "Число байт, требуемое для хранения первого поля:" << sizeof(Structure.StructureNumber) << ", второго поля:" << sizeof(Structure.StructureFirstChar) << ", третьего поля:" << sizeof(Structure.StructureElement) << endl;
	cout << "5 Пункт:" << endl;
	pi1 = (int)pi1;
	cout << "Преобразование 3.141592 в int: " << pi1 << endl;
	//cout << "число байт в преобразовании double в int:" << sizeof(pi1) << endl;
	pi = (int)pi;
	cout <<"Преобразование 3.14 в int: " << pi << endl;
	integer = (float)integer;
	cout << "Преобразование 2 в float: " << integer << endl;
	/*cout << "int + float + double = double" << endl;
	cout << "char + string = string" << endl;
	cout << "structure + int = НЕВОЗМОЖНО" << endl;
	cout << "structure + string = НЕВОЗМОЖНО" << endl;*/
	cout << "6 Пункт:" << endl;
	cout << "Имя типа -  " << typeid(integer).name() << endl;//int
	cout << "Имя типа -  " << typeid(Char).name() << endl;//char
	cout << "Имя типа -  " << typeid(3.14+3.141592).name() << endl;//double
	cout << "Имя типа -  " << typeid('C').name() << endl;//char
	cout << typeid(integer).before(typeid(pi)) << endl;// true
}