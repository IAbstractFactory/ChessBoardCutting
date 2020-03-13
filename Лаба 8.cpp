#include<iostream>
#include"ChessBoard.h"
using namespace std;
int main()
{
	ChessBoard board(6);
	for (int i = 1; i < 4; i++)
		board.Cut(0, i);



	return 0;
}