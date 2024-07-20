#include <iostream>


using namespace std;

int main() {
	float length = 0;
	float breadth = 0;
	float height = 0;
	float volume = 0;

	cin >> length;
	cin >> breadth;
	cin >> height;

	volume = length * breadth * height;
	cout << "Volume is " << volume << endl;
	return 0;
}