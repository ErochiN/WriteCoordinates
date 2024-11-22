#include "ConsolControl.h"

// ������������� ����������� ����������
// Initialization of static variables
int ConsolControl::ID = 0;
int ConsolControl::XSIZE = 1;
int ConsolControl::YSIZE = 1;
std::string** ConsolControl::ARRAYCONSOL = new std::string * [ConsolControl::YSIZE];

// ������� ��� ������ ������ � ���������� (ThisX, ThisY)
// Function to write text to the coordinates (ThisX, ThisY)
void ConsolControl::Write�oordinatesXY(std::string newText, int ThisX, int ThisY)
{
    // ������� ������ (��� Windows)
    // Clear the screen (for Windows)
    system("cls");

    // ���� ��� ������ �����, �������������� ������
    // If it's the first call, initialize the array
    if (ID == 0)
        FillArray();

    int tempX, tempY;

    // ���������� ����� ������� �������, ���� ���������� ��������� ������� ������
    // Determine new array sizes if coordinates exceed current size
    tempX = (ThisX > XSIZE) ? ThisX : XSIZE;
    tempY = (ThisY > YSIZE) ? ThisY : YSIZE;

    // ��������� ������� � ������ � ������ ���������
    // Add element to the array with new sizes
    AddElement(tempX, tempY);

    // ��������� ������� �������
    // Update current sizes
    XSIZE = tempX;
    YSIZE = tempY;

    // ���������� ����� ����� � ��������� ������ �������
    // Write new text to the specified array cell
    ARRAYCONSOL[ThisY - 1][ThisX - 1] = newText;

    // ������� ������� ������ �� �����
    // Print the current array to the screen
    PrintArray();

    // ����������� ID ��� ���������� ������
    // Increment ID for the next call
    ID++;
}

// ������� ��� ������������� ������� �����
// Function to initialize the array of strings
void ConsolControl::FillArray()
{
    ARRAYCONSOL[0] = new std::string[XSIZE];
}

// ������� ��� ������ ������� �� �����
// Function to print the array to the screen
void ConsolControl::PrintArray()
{
    // �������� �� ���� ������� �������
    // Iterate through all rows of the array
    for (int i = 0; i < YSIZE; i++)
    {
        // �������� �� ���� �������� � ������
        // Iterate through all columns in the row
        for (int j = 0; j < XSIZE; j++)
        {
            // ������� ������� ������� � ��������
            // Print array element with a space
            std::cout << ARRAYCONSOL[i][j] << " ";
        }
        std::cout << std::endl; // ������� �� ����� ������
    }
}

// ������� ��� ����������� ������ �� ������ ������� � ������
// Function to copy data from one array to another
void ConsolControl::CopeArray(std::string** newArr)
{
    // �������� ������ �� ARRAYCONSOL � ����� ������ newArr
    // Copy data from ARRAYCONSOL to the new array newArr
    for (int i = 0; i < YSIZE; i++)
    {
        for (int j = 0; j < XSIZE; j++)
        {
            newArr[i][j] = ARRAYCONSOL[i][j];
        }
    }
}

// ������� ��� ���������� �������� � ������ � ����������� ��� �������
// Function to add an element to the array with resizing
void ConsolControl::AddElement(int xAdd, int yAdd)
{
    // ������� ����� ������ � ������������ ���������
    // Create a new array with the increased size
    std::string** addString = new std::string * [yAdd];

    // �������������� ������ ������ �������
    // Initialize the rows of the new array
    for (int i = 0; i < yAdd; i++)
        addString[i] = new std::string[xAdd];

    // �������� ������ �� ������� ������� � �����
    // Copy data from the old array to the new one
    CopeArray(addString);

    // ����������� ������, ������� ������ ��������
    // Free memory occupied by the old array
    for (int i = 0; i < YSIZE; i++)
        delete[] ARRAYCONSOL[i];
    delete[] ARRAYCONSOL;

    // ������������� ��������� �� ����� ������
    // Set the pointer to the new array
    ARRAYCONSOL = addString;
}
