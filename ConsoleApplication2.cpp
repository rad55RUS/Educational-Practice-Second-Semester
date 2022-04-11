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
#include <stdint.h>
#include <ctime>
#include <chrono>


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

// Проверка на подсчитываемые символы
bool check_Counted_Symbols(char symbol)
{
    if (symbol == 'q' || symbol == 'Q' || symbol == 'w' || symbol == 'W' || symbol == 'e' || symbol == 'E' || symbol == 'r' || symbol == 'R' || symbol == 't' || symbol == 'T' || symbol == 'y'
        || symbol == 'Y' || symbol == 'u' || symbol == 'U' || symbol == 'i' || symbol == 'I' || symbol == 'o' || symbol == 'O' || symbol == 'p' || symbol == 'P' || symbol == 'a' || symbol == 'A'
        || symbol == 's' || symbol == 'S' || symbol == 'd' || symbol == 'D' || symbol == 'f' || symbol == 'F' || symbol == 'g' || symbol == 'G' || symbol == 'h' || symbol == 'H' || symbol == 'j'
        || symbol == 'J' || symbol == 'k' || symbol == 'K' || symbol == 'l' || symbol == 'L' || symbol == 'z' || symbol == 'Z' || symbol == 'x' || symbol == 'X' || symbol == 'c' || symbol == 'C'
        || symbol == 'v' || symbol == 'V' || symbol == 'b' || symbol == 'B' || symbol == 'n' || symbol == 'N' || symbol == 'm' || symbol == 'M' || symbol == '1' || symbol == '2' || symbol == '3'
        || symbol == '4' || symbol == '5' || symbol == '6' || symbol == '7' || symbol == '8' || symbol == '9' || symbol == '0')
        return true;
    else
        return false;
}

vector<string> quick_Sort(vector<string> array_to_sort)
{
    int array_to_sort_size = array_to_sort.size();
    if (array_to_sort.size() > 1) {
        vector<string> first_part(0), second_part(0);
        int first_part_size = first_part.size();
        int second_part_size = second_part.size();
        int max_size = 0, min_size = 100000;
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > max_size)
                max_size = array_to_sort[i].size();
            if (array_to_sort[i].size() < min_size)
                min_size = array_to_sort[i].size();
        }
        int mid_size = (max_size + min_size) / 2;
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > mid_size) {
                first_part_size++;
                first_part.resize(first_part_size);
                first_part[first_part_size-1] = array_to_sort[i];
            }
            else {
                second_part_size++;
                second_part.resize(second_part_size);
                second_part[second_part_size-1] = array_to_sort[i];
            }
            mid_size;
        }
        if (first_part_size != 0 and second_part_size != 0) {
            int j = 0;
            if (first_part_size > 1) {
                first_part_size = first_part.size();
                first_part = quick_Sort(first_part);
                for (j = 0; j < first_part_size; j++) {
                    array_to_sort[j] = first_part[j];
                }
            }
            else {
                array_to_sort[j] = first_part[0];
                j++;
                }
            if (second_part_size > 1) {
                second_part_size = second_part.size();
                second_part = quick_Sort(second_part);
                int k = 0;
                for (j; k < second_part_size; j++) {
                    array_to_sort[j] = second_part[k];
                    k++;
                }
            }
            else
                array_to_sort[j] = second_part[0];
        }
    }
    return array_to_sort;
}

void main()
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода

    ifstream input_file;

    string input_file_path;
    cout << "Введите путь или название файла с расширением: ";
    getline(cin, input_file_path);
    input_file.open(input_file_path);
    vector<string> word_array(1);
    string output_string;
    if (input_file.fail()) {

        cout << "\nПроизошла ошибка при открытии файла " << input_file_path;
    }
    else {
        int word_amount = 0, word_length = 0, char_amount = 0, j = 0, t = 0;
        ofstream output_file;
        output_file.open("Output.txt");
        ofstream result_file;
        result_file.open("result.txt");
        if (result_file.fail()) {

            cout << "\nПроизошла ошибка при открытии файла result.txt";
        }
        else if (output_file.fail()) {

            cout << "\nПроизошла ошибка при открытии файла Output.txt";
        }
        else {
            output_file << "Введенный текст: " << endl;
            while (getline(input_file, output_string)) {
                bool check_word = false;
                output_file << output_string << endl;
                for (int i = 0; i < output_string.size(); i++) {             // Подсчёт кол-ва слов в строке
                    if (check_word == false && !check_Counted_Symbols(output_string[i])) {
                        check_word = true;
                    }
                    if (check_word == true && check_Counted_Symbols(output_string[i])) {
                        check_word = false;
                        word_array[word_amount].resize(word_length);
                        word_amount++;
                        word_array.resize(word_array.size()+1);
                        word_length = 0;
                    }
                    if (check_word == false && check_Counted_Symbols(output_string[i])) {
                        word_length++;
                    }
                    char_amount++;
                }
                word_array[word_amount].resize(word_length);
                check_word = false;
                for (int i = 0; i < output_string.size(); i++) {
                    if (check_Counted_Symbols(output_string[i])) {
                        check_word = true;
                        word_array[t][j] = output_string[i];
                        j++;
                    }
                    else if (check_word == true) {
                        j = 0;
                        t++;
                        check_word = false;
                    }
                }
                j = 0;
            }
            auto start_time = chrono::high_resolution_clock::now();                                                         // Время начала сортировки
            word_array = quick_Sort(word_array);
            auto end_time = chrono::high_resolution_clock::now();                                                           // Время завершения сортировки
            auto search_time = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();             // Время сортировки
            input_file.clear();
            input_file .seekg(0, input_file.beg);
            cout << "\nВведенный текст:" << endl;
            while (getline(input_file, output_string)) {
                cout << output_string << endl;
            }
            output_file << "\nВариант 11: латиница, по кол-ву символов в слове, по убыванию, учитывать числа, быстрая сортировка" << endl;
            output_file << "Количество слов: " << word_amount++ << endl;
            output_file << "Время сортировки " << search_time << " миллисекунд" << endl;
            cout << "\nВариант 11: латиница, по кол-ву символов в слове, по убыванию, учитывать числа, быстрая сортировка" << endl;
            cout << "Количество слов: " << word_amount++ << endl;
            cout << "Время сортировки " << search_time << " миллисекунд" << endl;
            output_file.close();
            result_file << "Отсортированный массив: " << endl;
            for (int i = 0; i < word_array.size(); i++) {
                result_file << '[' << i << ']' << " - " << word_array[i] << endl;
            }
        }
    }

    input_file.close();
    cout << "\n\nНажмите ENTER, чтобы закрыть программу...";
    cin.get();
}