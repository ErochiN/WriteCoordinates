#pragma once
#include <iostream>

// Класс ConsolControl управляет консольным выводом, изменяя значения в двумерном массиве строк
// The ConsolControl class manages console output by modifying values in a 2D array of strings
class ConsolControl
{
public:
    // Статическая функция для записи текста в координаты (ThisX, ThisY)
    // Static function to write text to the coordinates (ThisX, ThisY)
    static void WriteСoordinatesXY(std::string newText, int ThisX, int ThisY);

private:
    // Статическое поле для уникального идентификатора, используемого для контроля состояния
    // Static field for a unique identifier used to track state
    static int ID;

    // Статическое поле для двумерного массива строк
    // Static field for a 2D array of strings
    static std::string** ARRAYCONSOL;

    // Статические поля для размера массива по осям X и Y
    // Static fields for array size in X and Y dimensions
    static int XSIZE, YSIZE;

    // Функция для инициализации массива
    // Function to initialize the array
    static void FillArray();

    // Функция для вывода массива на экран
    // Function to print the array to the screen
    static void PrintArray();

    // Функция для копирования данных из одного массива в другой
    // Function to copy data from one array to another
    static void CopeArray(std::string** newArr);

    // Функция для добавления нового элемента в массив с увеличением его размера
    // Function to add a new element to the array, resizing it
    static void AddElement(int xAdd, int yAdd);
};
