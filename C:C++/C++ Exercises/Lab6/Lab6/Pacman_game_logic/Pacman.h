#pragma once
#include "Coin.h"
#define MAX_COUNT  100


class Pacman {
	private: 
		Coin* coins[MAX_COUNT];
		int coinCount;
		int totalValue;

	public:
		Pacman();
		~Pacman();
		void printInfo(void);
		bool addCoin(Coin* coin);
		bool removeCoin(int index);
};