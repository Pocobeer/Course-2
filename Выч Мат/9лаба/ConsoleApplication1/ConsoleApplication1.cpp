#include <iostream>
using namespace std;
double func(double x) {
    return x*x;
    //return cos(3 * x) / (x * x + 1);
}
int main()
{
    int n = 10;//n = 10
    double a = 0, b = 1,eps = 1e-4;// a=1, b=2
    double h = (b - a) / n;
    //f(x) = x^2;
    double sum = 0;
    double sum1 = 0;
    double Str=0, Spr=0, Simp=0;
    for (double i = a; i < b-h; i+=h) {
        Str += h * (func(i) + func(i+h)) / 2;
        Spr += func(i + h / 2) * h;
    }
    for (double j = a+h; j <= b - h; j += 2 * h) {
            sum +=func(j) ;
    }
    for (double i = a + 2*h; i <= b - 2 * h; i += 2 * h) {
        sum1 += func(i);
    }
    cout << "S pryam = " << Spr << endl;
    cout <<"S trap = " << Str << endl;
    Simp = h / 3 * (func(a) + func(b) + 4 * sum + 2 * sum1);
    cout << "S simp = " << Simp << endl;
    int count = 1;
    
    n = 2;
    double fr1 = 0, fr2 = 0;
    do {
        fr1 = 0, fr2 = 0;
        h = (b - a) / n;
        for (double i = a; i < b; i += h) {
            fr1 += func(i + h / 2) * h;
        }
        
        n *= 2;
        h = (b - a) / n;
        for (double i = a; i < b; i += h) {
            fr2 += func(i + h / 2) * h;
        }
        cout << count << ". fR2 = " << fr2 << " n = " << n << endl;
        count++;
    } while (fabs(fr2 - fr1) / 3 >= 0.0001);
}
