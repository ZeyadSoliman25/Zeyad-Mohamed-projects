#include "Coin.h"
#include "Pacman.h"
#include "Grid.h"
#include <iostream>
using namespace std;

void testCoinClass() {
	Coin c1(10);
	Coin c2(20);
	cout << "Coin 1: ";
	c1.printInfo();
	cout << "\nCoin 2: ";
	c2.printInfo();
	cout << "\n";
}


void testPacmanClass() {
	Pacman p1, p2, p3;
	Coin c1(10), c2(20), c3(30), c4(40), c5(50);
	bool Is_removed = false;
	p1.printInfo();
	cout << "\n";
	p1.addCoin(&c1);
	p1.printInfo();
	cout << "\n";
	p1.addCoin(&c2);
	p1.addCoin(&c3);
	p1.printInfo();
	cout << "\n";
	p2.printInfo();

	Is_removed = p2.removeCoin(2);
	if (Is_removed) {
		p2.printInfo();
	}
	else {
		cout << "\nCoin couldn't be removed";
	}

	cout << "\n";
	p2.addCoin(&c1);
	p2.printInfo();

	Is_removed = p2.removeCoin(2);
	if (Is_removed) {
		p2.printInfo();
	}
	else {
		cout << "\nCoin couldn't be removed";
	}

	Is_removed = p2.removeCoin(1);
	if (Is_removed) {
		p2.printInfo();
	}
	else {
		cout << "\nCoin couldn't be removed";
	}

	cout << "\n";
	p3.printInfo();

	p3.addCoin(&c1);
	p3.addCoin(&c2);
	p3.addCoin(&c3);
	p3.addCoin(&c4);
	p3.addCoin(&c5);

	p3.printInfo();
	cout << "\n";

	p3.addCoin(&c1);
	p3.printInfo();
	cout << "\n";

	Is_removed = p3.removeCoin(3);
	if (Is_removed) {
		p3.printInfo();
	}
	else {
		cout << "\nCoin couldn't be removed";
	}
}


void testGridClass() {
	Grid g1,g2;
	Pacman p1, p2;
	Coin c1(10), c2(20), c3(30), c4(40), c5(50), c6(60);
	g1.printGrid();

	g1.setCoin(7, 4, &c1);
	g1.setCoin(1, 3, &c2);
	g1.printGrid();

	g1.setCoin(1, 3, &c3);

	g1.movePacman(7, 4);
	g1.movePacman(1, 3);
	p1 = g1.getPacman();
	g1.printGrid();
	p1.printInfo();
	cout << "\n";

	g2.setCoin(1, 1, &c1);
	g2.setCoin(2, 2, &c2);
	g2.setCoin(3, 3, &c3);
	g2.setCoin(4, 4, &c4);
	g2.setCoin(5, 5, &c5);
	g2.setCoin(6, 6, &c6);
	g2.printGrid();

	g2.movePacman(1, 1);
	g2.movePacman(2, 2);
	g2.movePacman(3, 3);
	g2.movePacman(4, 4);
	g2.movePacman(5, 5);
	g2.movePacman(6, 6);
	p2 = g2.getPacman();
	g2.printGrid();
	p2.printInfo();

}

int main() {
	testCoinClass();
	testPacmanClass();
	testGridClass();
}

