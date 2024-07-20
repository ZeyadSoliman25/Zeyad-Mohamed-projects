#pragma once
#include <iostream>
using namespace std;

template <typename T> 
class Matrix
{
private:
	T data[5][7];

public:
	bool AddValue(int row, int col, T value)
	{
		if ( (row > 4 ) || (col > 6) )
		{
			return false;
		}
		else
		{
			data[row][col] = value;
		}
	}

	bool BelongTo(T value)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (data[i][j] == value)
				{
					return true;
				}
			}
		}

		return false;
	}

	void PrintRow(int row)
	{
		if (row > 4)
		{
			cout << "Not correct row number" << endl;
		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				cout << data[row][i] << " ";
			}
			cout << "\n";
		}
	}

	void Print(void)
	{
		cout << "[ " << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "\t [ ";
			for (int j = 0; j < 7; j++)
			{
				cout << data[i][j] << ' ';
			}
			cout << "] \n";
		}

		cout << "] \n";
	}

	T MaxValue()
	{
		T max = data[0][0];

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (data[i][j] > max)
				{
					max = data[i][j];
				}
			}
		}

		return max;
	}
};