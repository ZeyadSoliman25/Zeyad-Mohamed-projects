#include <iostream>


using namespace std;

int main() {
	int num1 = 0;
	int num2 = 0;
	char op = 0;
	int result = 0;

	cout << "Enter first number: ";
	cin >> num1;
	cout << "\n";
	cout << "Enter second number: ";
	cin >> num2;
	cout << "\n";
	cout << "Choose operator (*,+,-): ";
	cin >> op;
	cout << "\n";

	switch (op) {
	case '*':
		result = num1 * num2;
		break;
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	}

	cout << result << endl;
	return 0;
}