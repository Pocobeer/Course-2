#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct sample {
	sample(int x, int y) : sample(4.5) { cout << 4; };
	sample(float x) :sample(3, x) { cout << 3; };
	sample(int x, float y) { cout << 2; };
	sample() : sample(3, 4) { cout << 1; };
};
int main() {
	sample smp;
	return 0;
}
