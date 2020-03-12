#include<iostream>
#include"Field.h"
using namespace std;
int main()
{
	Field field(6);
	for (int i = 1; i < 4; i++)
		field.Cut(0, i);



	return 0;
}