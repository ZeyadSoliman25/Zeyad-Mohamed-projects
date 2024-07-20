#include <iostream>
using namespace std;

bool CountAdults(int ptr1[], int size, int* count_adults, int* count_young) {
	bool all_adults = true;
	for (int i = 0; i < size; i++) {
		if (ptr1[i] >= 18) {
			(*count_adults)++;
		}
		else {
			(*count_young)++;
			all_adults = false;
		}
	}
	return all_adults;
}


void main(void) {
	int count_adults = 0;
	int count_young = 0;
	int size = 10;
	int arr[10] = { 0 };
	bool all_adults = true;

	cout << "Enter the ages of " << size << " people: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i]; 
	}

	all_adults = CountAdults(arr, size, &count_adults, &count_young);

	cout << "Number of adults: " << count_adults << endl;
	cout << "Number of non-adults: " << count_young << endl;

	if (all_adults) {
		cout << "All people are adult";
	}
	else {
		cout << "Not all ages are adults.";
	}
}