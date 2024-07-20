#include <iostream>


using namespace std;

int main() {
	int num = 0;
	int sum = 0;

	cout << "Enter the end of range: " << endl;
	cin >> num ;

	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) {
			sum += i;
		}
	}

	cout << "Sum if even numbers from 1 to " << num << " is " << sum << endl;
	return 0;
}