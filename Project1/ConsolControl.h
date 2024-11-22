#pragma once
#include <iostream>

class ConsolControl
{
public:
	static void Write—oordinatesXY(std::string newText, int ThisX, int ThisY);

private:
	static int ID;
	static std::string** ARRAYCONSOL;
	static int XSIZE, YSIZE;

	static void FillArray();
	static void PrintArray();
	static void CopeArray(std::string** newArr);
	static void AddElement(int xAdd, int yAdd);
};