#include <iostream>
using namespace std;


int ExtractGradesAndIndices(int* ptr1, int size, int grade, int ptr2[], int ptr3[])
{
	int j = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (ptr1[i] >= grade) {
			count++;
		}
	}


	for (int i = 0; i < size; i++) {
		if (ptr1[i] >= grade) {
			ptr2[j] = ptr1[i];
			ptr3[j] = i;
			j++;
		}
	}

	return count; 
}


void main(void) {
	int size = 0;
	int grade = 0;
	int count = 0;

	cout << "Enter the number of students: ";
	cin >> size;

	int* ptr_grades = new int [size];
	int* ptr_equal_grades = new int[size];
	int* ptr_indices = new int[size];
	cout << "Enter the student scores: ";
	for (int i = 0; i < size; i++) {
		cin >> ptr_grades[i];
	}

	cout << "Enter the specified grade: ";
	cin >> grade;

	count = ExtractGradesAndIndices(ptr_grades, size, grade, ptr_equal_grades, ptr_indices);

	cout << "Grades greater than or equal to " << grade << ": ";
	for (int i = 0; i < count; i++) {
		cout << ptr_equal_grades[i] << " ";
	}

	cout << "\nIndices of matching grades: "; 
	for (int i = 0; i < count; i++){
		cout << ptr_indices[i] << " ";
	}
}

