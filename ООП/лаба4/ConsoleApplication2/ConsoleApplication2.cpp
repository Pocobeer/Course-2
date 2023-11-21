
#include <iostream>
using namespace std;
struct Structure {
    int a;
};
Structure add;
Structure *add_ptr = &add;
int funct(int a) {
    return a * a;
}
int (*funct_ptr)(int) = &funct;
int main()
{
    int obj;
    int *ptr_obj = &obj;
    *ptr_obj = 1;
    cout << ptr_obj << " " << *ptr_obj << endl;
    add.a = 10;
    double obj_1 = 3.14;
    void* ptr_void = &add;
    cout << (static_cast<Structure*>(ptr_void))->a << endl;
    cout << ((Structure*)(ptr_void))->a << endl;
    cout << funct(2) << endl;
    cout << funct_ptr(2) << endl;

}
