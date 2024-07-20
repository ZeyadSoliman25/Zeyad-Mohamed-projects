#include"Pacman.h"
#include <iostream>
using namespace std;

Pacman::Pacman() {
	coinCount = 0;
	totalValue = 0;

	for (int i = 0; i < MAX_COUNT; i++) {
		coins[i] = NULL;
	}
}

Pacman :: ~Pacman() {
	cout << "\nPacman is destroyed\n";
}


void Pacman::printInfo() {
	cout << "\nPacman has " << coinCount << " coins\n";
	for (int i = 0; i < coinCount; i++) {
		cout << "Coin " << i+1 << ": ";
		coins[i]->printInfo();
		cout << "\n";
	}
	cout << "Total value: " << totalValue;
}


bool Pacman::addCoin(Coin* coin) {
	if (coinCount < MAX_COUNT) {
		coins[coinCount] = coin;
		coinCount++;
		totalValue += coin->get_Value();
		return true;
	}
	else {
		return false;
	}
}


bool Pacman::removeCoin(int index) {
	if (index >= 0 && index < coinCount) {
		for (int i = 0; i < coinCount; i++) {
			if (index == i) {
				totalValue -= coins[i]->get_Value();
				coins[i] = coins[coinCount-1];
				coinCount--;
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}
