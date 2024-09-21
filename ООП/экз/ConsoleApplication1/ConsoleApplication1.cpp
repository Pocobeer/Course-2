#include <iostream>
#include<iomanip>
using namespace std;
class Mass {
    int size;
    int* p;

public:
    Mass() {};
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

class Int {
private:
    int value;

public:
    Int(int v) : value(v) {}

    Int operator+(const Int& other) {
        return Int(value + other.value);
    }

    Int operator-(const Int& other) {
        return Int(value - other.value);
    }

    Int operator*(const Int& other) {
        return Int(value * other.value);
    }


    
    bool operator==(const Int& other){
        return value == other.value;
    }

    bool operator!=(const Int& other){
        return value != other.value;
    }

    bool operator<(const Int& other){
        return value < other.value;
    }

    bool operator<=(const Int& other){
        return value <= other.value;
    }

    bool operator>(const Int& other){
        return value > other.value;
    }

    bool operator>=(const Int& other){
        return value >= other.value;
    }

    operator int()  {
        return value;
    }

    void print()  {
        cout << value << endl;
    }

};

int main() {
    setlocale(LC_ALL, "rus");
    int arr_int[8] = { 1,2,3,4,5,6,7,8 };
    Mass arr(arr_int, 8);
    arr.Out_arr();
    cout << arr[1] << endl;

    Int a = 5;
    Int b = 10;
    Int c = a + b;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    cout << "a + b: " << a + b << endl;
    cout << "a - b: " << a - b << endl;
    cout << "a * b: " << a * b << endl;
    cout << "a == b: " << (a == b) << endl;
}