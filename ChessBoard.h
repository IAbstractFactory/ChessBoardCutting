#pragma once
#include <stdio.h>
class ChessBoard
{
	char** arr;
	int Size;
	int count = 0;
	
	
public:
	long HowMuch = 0;
	ChessBoard(int size)
	{
		Size = size + 1;
		arr = new char* [Size];
		for (int i = 0; i < Size; i++)
		{
			arr[i] = new char[Size];
		}
		Refresh();

	}
	void Refresh()
	{
		for (int i = 0; i < Size; i++)
			for (int j = 0; j < Size; j++)
				arr[i][j] = '*';
	}
	void Show()
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
				printf("%c ", arr[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	void Clear(int i, int j)
	{
		arr[i][j] = '*';
		arr[Size - i - 1][Size - j - 1] = '*';

	}
	void Cut(int i, int j)
	{
		arr[i][j] = count + '0';
		arr[Size - 1 - i][Size - 1 - j] = count + '0';
		count++;
		if (i == (Size - 1) / 2 && j == (Size - 1) / 2)
		{
			Show();
			//printf("%ld\n", ++HowMuch);
		}
		else
		{
			if (i + 1 < Size - 1 && arr[i + 1][j] == '*')Cut(i + 1, j);
			if (i - 1 > 0 && arr[i - 1][j] == '*')Cut(i - 1, j);
			if (j + 1 < Size - 1 && i != 0 && arr[i][j + 1] == '*')Cut(i, j + 1);
			if (j - 1 > 0 && i != 0 && arr[i][j - 1] == '*')Cut(i, j - 1);

		}
		count--;
		Clear(i, j);

	}
};

