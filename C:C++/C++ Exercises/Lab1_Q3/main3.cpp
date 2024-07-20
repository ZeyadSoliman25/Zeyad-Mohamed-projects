#include <iostream>


using namespace std;

int main() {
	char letter = 0;
	
	cout << "Enter a character to check, q is for quiting program" << endl;
	while (1) {
		cin >> letter;
		if (letter == 'q') {
			break;
		}
		if (letter >= 97 && letter <= 122) {
			cout << "The letter is a lower case letter" << endl;
		}
		else if (letter >= 65 && letter <= 90) {
			cout << "The letter is an upper case letter" << endl;
		}
	}
	return 0;
}