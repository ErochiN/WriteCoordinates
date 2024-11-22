#include "ConsolControl.h"

// Инициализация статических переменных
// Initialization of static variables
int ConsolControl::ID = 0;
int ConsolControl::XSIZE = 1;
int ConsolControl::YSIZE = 1;
std::string** ConsolControl::ARRAYCONSOL = new std::string * [ConsolControl::YSIZE];

// Функция для записи текста в координаты (ThisX, ThisY)
// Function to write text to the coordinates (ThisX, ThisY)
void ConsolControl::WriteСoordinatesXY(std::string newText, int ThisX, int ThisY)
{
    // Очистка экрана (для Windows)
    // Clear the screen (for Windows)
    system("cls");

    // Если это первый вызов, инициализируем массив
    // If it's the first call, initialize the array
    if (ID == 0)
        FillArray();

    int tempX, tempY;

    // Определяем новые размеры массива, если координаты превышают текущий размер
    // Determine new array sizes if coordinates exceed current size
    tempX = (ThisX > XSIZE) ? ThisX : XSIZE;
    tempY = (ThisY > YSIZE) ? ThisY : YSIZE;

    // Добавляем элемент в массив с новыми размерами
    // Add element to the array with new sizes
    AddElement(tempX, tempY);

    // Обновляем текущие размеры
    // Update current sizes
    XSIZE = tempX;
    YSIZE = tempY;

    // Записываем новый текст в указанную ячейку массива
    // Write new text to the specified array cell
    ARRAYCONSOL[ThisY - 1][ThisX - 1] = newText;

    // Выводим текущий массив на экран
    // Print the current array to the screen
    PrintArray();

    // Увеличиваем ID для следующего вызова
    // Increment ID for the next call
    ID++;
}

// Функция для инициализации массива строк
// Function to initialize the array of strings
void ConsolControl::FillArray()
{
    ARRAYCONSOL[0] = new std::string[XSIZE];
}

// Функция для вывода массива на экран
// Function to print the array to the screen
void ConsolControl::PrintArray()
{
    // Проходим по всем строкам массива
    // Iterate through all rows of the array
    for (int i = 0; i < YSIZE; i++)
    {
        // Проходим по всем столбцам в строке
        // Iterate through all columns in the row
        for (int j = 0; j < XSIZE; j++)
        {
            // Выводим элемент массива с пробелом
            // Print array element with a space
            std::cout << ARRAYCONSOL[i][j] << " ";
        }
        std::cout << std::endl; // Переход на новую строку
    }
}

// Функция для копирования данных из одного массива в другой
// Function to copy data from one array to another
void ConsolControl::CopeArray(std::string** newArr)
{
    // Копируем данные из ARRAYCONSOL в новый массив newArr
    // Copy data from ARRAYCONSOL to the new array newArr
    for (int i = 0; i < YSIZE; i++)
    {
        for (int j = 0; j < XSIZE; j++)
        {
            newArr[i][j] = ARRAYCONSOL[i][j];
        }
    }
}

// Функция для добавления элемента в массив с увеличением его размера
// Function to add an element to the array with resizing
void ConsolControl::AddElement(int xAdd, int yAdd)
{
    // Создаем новый массив с увеличенными размерами
    // Create a new array with the increased size
    std::string** addString = new std::string * [yAdd];

    // Инициализируем строки нового массива
    // Initialize the rows of the new array
    for (int i = 0; i < yAdd; i++)
        addString[i] = new std::string[xAdd];

    // Копируем данные из старого массива в новый
    // Copy data from the old array to the new one
    CopeArray(addString);

    // Освобождаем память, занятую старым массивом
    // Free memory occupied by the old array
    for (int i = 0; i < YSIZE; i++)
        delete[] ARRAYCONSOL[i];
    delete[] ARRAYCONSOL;

    // Устанавливаем указатель на новый массив
    // Set the pointer to the new array
    ARRAYCONSOL = addString;
}
