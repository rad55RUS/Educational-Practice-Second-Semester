#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include <cmath>
#include <math.h>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
bool check = false, isd = true;
char number[256], * p = number;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Проверка на число часть - 1
bool isd_func()
{
    while (*p)
        if (!isdigit(unsigned char(*p++)))
        {
            isd = false;
            break;
        }
    if (abs(atof(number)) != (int)atof(number))
        isd = true;
    return isd;
}

// Проверка на число часть - 2
int check_number(double num)
{
    while (check == false) // Проверка числа N
    {
        isd = true;
        cout << "\nПожалуйста, введите число: ";
        cin >> number;
        p = number;
        isd_func();
        if (isd == true)
            check = true;
        num = atof(number);
    }
    return num;
}

// Ввод числа
double enter_Number()
{
    cin >> number;
    p = number;
    isd_func();
    if (isd == true)
        check = true;
    double num = atof(number);
    check_number(num);
    num = atof(number);
    check = false;
    return num;
}

void main()
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода

    ifstream input_file;

    input_file.open("Input.txt");
    string input_string;

    if (input_file.fail()) {

        cout << "Произошла ошибка при открытии файла Input.txt";
    }
    else {
        ofstream output_file;
        output_file.open("Output.txt");
        if (input_file.fail()) {

            cout << "Произошла ошибка при открытии файла Output.txt";
        }
        else {
            while (getline(input_file, input_string)) {
                output_file << input_string << endl;
            }
            output_file.close();

            input_file.clear();
            input_file .seekg(0, input_file.beg);
            cout << "Исходный текст: " << endl;
            while (getline(input_file, input_string)) {
                cout << input_string << endl;
            }
        }
    }

    input_file.close();
    cout << "\n\nНажмите ENTER, чтобы закрыть программу...";
    cin.get();
}