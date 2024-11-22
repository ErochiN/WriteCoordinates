#include "ConsolControl.h"

int ConsolControl::ID = 0;
int ConsolControl::XSIZE = 1;
int ConsolControl::YSIZE = 1;
std::string** ConsolControl::ARRAYCONSOL = new std::string * [ConsolControl::YSIZE];

void ConsolControl::WriteÑoordinatesXY(std::string newText, int ThisX, int ThisY)
{
	system("cls");

	if (ID == 0)
		FillArray();

	int tempX, tempY;

	tempX = (ThisX > XSIZE) ? ThisX : XSIZE;
	tempY = (ThisY > YSIZE) ? ThisY : YSIZE;

	AddElement(tempX, tempY);
	XSIZE = tempX;
	YSIZE = tempY;

	ARRAYCONSOL[ThisY - 1][ThisX - 1] = newText;
	PrintArray();
	ID++;
}

void ConsolControl::FillArray()
{
	ARRAYCONSOL[0] = new std::string[XSIZE];
}

void ConsolControl::PrintArray()
{
	for (int i = 0; i < YSIZE; i++)
	{
		for (int j = 0; j < XSIZE; j++)
		{
			std::cout << ARRAYCONSOL[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void ConsolControl::CopeArray(std::string** newArr)
{
	for (int i = 0; i < YSIZE; i++)
	{
		for (int j = 0; j < XSIZE; j++)
		{
			newArr[i][j] = ARRAYCONSOL[i][j];
		}
	}
}

void ConsolControl::AddElement(int xAdd, int yAdd)
{
	std::string** addString = new std::string * [yAdd];

	for (int i = 0; i < yAdd; i++)
		addString[i] = new std::string[xAdd];

	CopeArray(addString);

	for (int i = 0; i < YSIZE; i++)
		delete[] ARRAYCONSOL[i];
	delete[] ARRAYCONSOL;

	ARRAYCONSOL = addString;
}
