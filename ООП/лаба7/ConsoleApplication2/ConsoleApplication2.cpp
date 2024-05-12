#include <iostream>
#include <string>
using namespace std;
class B1 {
protected:
    int b;
public:
    B1() = default;
    B1(int b1) : b(b1) {};
    virtual void Out() {
        cout << "B1: " << b << endl;
    }
    ~B1() = default;
};

class D : public B1 {
    int d;
public:
	D() = default;
	D(int b1, int d1) : B1(b1) {
        d = d1;
    };
    void Out() {
        cout << "Class B1: " << B1::b << endl;
		cout << d << endl;
    }
    ~D () = default;
};

int main()
{
    D d;
    B1 b1 = d;
    B1 b2 = (B1)d;
    B1* bb1 = new B1;
    D* d1 = new D(1, 3);
    d1 = dynamic_cast<D*>(bb1);

}
