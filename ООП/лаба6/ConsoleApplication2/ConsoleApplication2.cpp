#include <iostream>
#include<string>
using namespace std;
class Test_14 {
	int* Ext;
public:
	
	Test_14() {
		Ext = new int;
	}
	Test_14(int a) {
		Ext = new int(a);

	}
	~Test_14() = default;
		//delete Ext;
	//}
	Test_14& operator=(const Test_14& Other) {
		/*if (this != &Other) {
			delete Ext;
		}*/
		Ext = new int;
		Ext = Other.Ext;
		return *this;
	}
	void Out() {
		cout << "Element: " << *Ext << endl;
	}
};
int main() {
	Test_14 c1(15);
	Test_14 c2 = c1;
	c1.Out();
	c2.Out();
}