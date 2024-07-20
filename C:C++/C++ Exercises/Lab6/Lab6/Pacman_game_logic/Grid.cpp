#include "Grid.h"
#include <iostream>
using namespace std;


Grid::Grid() {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			CoinGrid[i][j] = NULL;
		}
	}
}


Grid::~Grid() {
	cout << "Grid is destroyed\n";
}


void Grid::printGrid() {
	Coin* coins_in_grid[GRID_SIZE][GRID_SIZE] = { NULL };
	cout << "\n";
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (CoinGrid[i][j] != NULL) {
				cout << "C";
			}
			else {
				cout << "-";
			}
		}
		cout << "\n";
	}
	cout << "\n";

	for (int m = 0; m < GRID_SIZE; m++) {
		for (int n = 0; n < GRID_SIZE; n++) {
			if (coins_in_grid[m][n] != NULL) {
				cout << "Coin at (" << m << "," << n << "): ";
				coins_in_grid[m][n]->printInfo();
				cout << "\n";
			}
		}
	}
}


void Grid::setCoin(int x, int y, Coin* coin) {
	CoinGrid[x][y] = coin;
}


Coin* Grid::popCoin(int x, int y) {
	Coin* coin_ptr = CoinGrid[x][y];
	CoinGrid[x][y] = NULL;
	return coin_ptr;
}


void Grid::movePacman(int x, int y) {
	if (CoinGrid[x][y] != NULL) {
		p1.addCoin(CoinGrid[x][y]);
		popCoin(x,y);
	}
}


Pacman Grid::getPacman() {
	return p1;
}