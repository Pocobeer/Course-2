#include <iostream>
#include <string>
using namespace std;
int calculating_expression(string expression, int& index) {
	if (index > expression.length()) {
		return 0;
	}
	char Char = expression[index];
	index++;
	if (Char == '+' || Char == '-' || Char == '*' || Char == '/') {
		int operand1 = calculating_expression(expression, index);
		int operand2 = calculating_expression(expression, index);
		if (Char == '+') {
			return operand1+operand2;
		}
		if (Char == '-') {
			return operand1 - operand2;
		}
		if (Char == '*') {
			return operand1 * operand2;
		}
		if (Char == '/') {
			return operand1 / operand2;
		}
	}
	return Char - '0';
}
int main() {
	string expression;
	int index = 0;
	cout << "Enter the expression: " << endl;
	cin >> expression;
	int result = calculating_expression(expression, index);
	cout << "Expression value: " << result << endl;
}