#pragma once
#include "Pacman.h"
#include "Coin.h"

#define GRID_SIZE 10

class Grid {
	private:
		Pacman p1;
		Coin* CoinGrid[GRID_SIZE][GRID_SIZE];

	public:
		Grid();
		~Grid();
		void setCoin(int x, int y, Coin* coin);
		Coin* popCoin(int x, int y);
		void printGrid();
		void movePacman(int x, int y); 
		Pacman getPacman();
};