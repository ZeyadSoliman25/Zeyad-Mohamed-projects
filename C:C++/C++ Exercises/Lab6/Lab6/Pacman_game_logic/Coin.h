#pragma once

class Coin {
	private:
		int Value;

	public:
		Coin();
		Coin(int value);
		int get_Value();
		void set_value(int value);
		void printInfo();
};
