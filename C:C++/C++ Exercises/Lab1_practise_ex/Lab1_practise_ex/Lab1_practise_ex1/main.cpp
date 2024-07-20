#include <iostream>
using namespace std;

int CountLtr(char arr[], int n, char ltr);


void main() {
	int n = 0;
	char* arr;
	char letter_to_be_checked = 0;
	int count = 0;

	cout << "Enter the size of array: ";
	cin >> n;

	cout << "Enter the letter to be checked: ";
	cin >> letter_to_be_checked; 

	cout << "Enter the characters: ";

	arr = new char[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	count = CountLtr(arr, n, letter_to_be_checked);
	cout << "The number of repeated letter: " << count;

}

int CountLtr(char arr[], int n, char ltr) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if ((arr[i] == ltr) || (arr[i] == ltr+32) || (arr[i] == ltr - 32)) {
			count++;
		}
	}
	return count;
}


