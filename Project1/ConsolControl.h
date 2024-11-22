#pragma once
#include <iostream>

// ����� ConsolControl ��������� ���������� �������, ������� �������� � ��������� ������� �����
// The ConsolControl class manages console output by modifying values in a 2D array of strings
class ConsolControl
{
public:
    // ����������� ������� ��� ������ ������ � ���������� (ThisX, ThisY)
    // Static function to write text to the coordinates (ThisX, ThisY)
    static void Write�oordinatesXY(std::string newText, int ThisX, int ThisY);

private:
    // ����������� ���� ��� ����������� ��������������, ������������� ��� �������� ���������
    // Static field for a unique identifier used to track state
    static int ID;

    // ����������� ���� ��� ���������� ������� �����
    // Static field for a 2D array of strings
    static std::string** ARRAYCONSOL;

    // ����������� ���� ��� ������� ������� �� ���� X � Y
    // Static fields for array size in X and Y dimensions
    static int XSIZE, YSIZE;

    // ������� ��� ������������� �������
    // Function to initialize the array
    static void FillArray();

    // ������� ��� ������ ������� �� �����
    // Function to print the array to the screen
    static void PrintArray();

    // ������� ��� ����������� ������ �� ������ ������� � ������
    // Function to copy data from one array to another
    static void CopeArray(std::string** newArr);

    // ������� ��� ���������� ������ �������� � ������ � ����������� ��� �������
    // Function to add a new element to the array, resizing it
    static void AddElement(int xAdd, int yAdd);
};
