#include "Coin.h"
#include <iostream>
using namespace std;

Coin::Coin(int value) {
	if (value > 0) {
		Value = value; 
	}
	else {
		Value = 1;
	}
}

Coin::Coin() {
	Value = 1;
}


int Coin::get_Value() {
	return Value;
}

void Coin::set_value(int value) {
	Value = value;
}

void Coin::printInfo() {
	cout << Value << " value";
}