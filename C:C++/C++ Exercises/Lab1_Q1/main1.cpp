#include <iostream>


using namespace std;

int main() {
	int sum_fives = 0;
	int sum_nonfives = 0;
	int count = 0;
	int num = 0;
	float average_nonfives = 0;

	cout << "Enter 6 numbers:\n";
	for (int i = 0; i < 6; i++) {
		cin >> num; 
		if (num%5 == 0) {
			sum_fives += num;
		}
		else{
			count++;
			sum_nonfives += num;
		}
	}
	if (count == 0) {
		count = 1;
	}
	average_nonfives = sum_nonfives / count;
	cout << "Sum of multiple of fives = " << sum_fives << endl;
	cout << "Average of non-multiples = " << average_nonfives << endl;
	return 0;
}