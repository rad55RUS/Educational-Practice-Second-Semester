#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

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
#include <filesystem>
#include <experimental/filesystem>

namespace fs = ::std::experimental::filesystem;
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

// Быстрая сортировка
vector<string> quick_Sort(vector<string> array_to_sort)
{
    int array_to_sort_size = array_to_sort.size();
    if (array_to_sort_size > 1) {
        vector<string> first_part(0), second_part(0);
        int first_part_size = first_part.size();
        int second_part_size = second_part.size();
        int max_size = 0, min_size = 100000;

        // Поиск опорного элемента
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > max_size)
                max_size = array_to_sort[i].size();
            if (array_to_sort[i].size() < min_size)
                min_size = array_to_sort[i].size();
        }
        int mid_size = (max_size + min_size) / 2;
        //

        // Разделение массива
        for (int i = 0; i < array_to_sort_size; i++) {
            if (array_to_sort[i].size() > mid_size) {
                first_part_size++;
                first_part.resize(first_part_size);
                first_part[first_part_size - 1] = array_to_sort[i];
            }
            else {
                second_part_size++;
                second_part.resize(second_part_size);
                second_part[second_part_size - 1] = array_to_sort[i];
            }
        }
        //

        // Работа с рекурсией и составление готового массива
        if (first_part_size != 0 && second_part_size != 0) {
            int j = 0;
            if (first_part_size > 1) {
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

// Составление массива слов с их подсчётом
vector<string> word_Counting(ifstream& input_file, string output_string, int& word_amount)
{
    int word_length = 0, char_amount = 0, t = 0, j = 0;
    vector<string> word_array(1);
    bool check_word = false;

    while (getline(input_file, output_string)) {
        check_word = false;
        for (int i = 0; i < output_string.size(); i++)
            if (check_Counted_Symbols(output_string[i])) {
                check_word = true;
                break;
            }
        if (output_string.size() > 0 && word_amount > 0 && check_word == true && check_Counted_Symbols(output_string[0])) {
            word_amount++;
            word_array.resize(word_array.size() + 1);
        }
        check_word = false;
        for (int i = 0; i < output_string.size(); i++) {
            if (check_word == false && !check_Counted_Symbols(output_string[i])) {
                check_word = true;
            }
            if (check_word == true && check_Counted_Symbols(output_string[i])) {
                check_word = false;
                word_array[word_amount].resize(word_length);
                word_amount++;
                word_array.resize(word_array.size() + 1);
                word_length = 0;
            }
            if (check_word == false && check_Counted_Symbols(output_string[i])) {
                word_length++;
            }
            char_amount++;
        }
        if (output_string.size() > 0) {
            if (word_length > 0) {
                word_array[word_amount].resize(word_length);
            }
        }
        check_word = false;
        for (int i = 0; i < output_string.size(); i++) {
            if (check_Counted_Symbols(output_string[i])) {
                check_word = true;
                word_array[t][j] = output_string[i];
                j++;
            }
            else if (check_word == true) {
                word_array[t].resize(j);
                j = 0;
                t++;
                check_word = false;
            }
        }
        if (check_word == true)
            t++;
        j = 0;
        word_length = 0;
    }
    return word_array;
}
//

// Нахождение количества слов каждой длины
vector<int> each_Length_Words(vector<string> word_array)
{
    int max_length = 0;
    vector<int> word_amount_by_length(0);

    for (int i = 0; i < word_array.size(); i++) {
        if (word_array[i].size() > max_length) {
            max_length = word_array[i].size();
            word_amount_by_length.resize(max_length);
        }
        word_amount_by_length[word_array[i].size() - 1]++;
    }
    return word_amount_by_length;
}
//

// Очистка от пустых элементов
vector<string> clear_Empty_Elements(vector<string> array_to_clear, int& word_amount)
{
    for (int i = 0; i < array_to_clear.size(); i++) {
        if (array_to_clear[i][0] == NULL) {
            array_to_clear.erase(array_to_clear.begin() + i);
            word_amount--;
        }
    }
    return array_to_clear;
}

void main()
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода

    ifstream input_file;

    string input_file_path;
    cout << "Введите полный путь или название файла с расширением: ";
    getline(cin, input_file_path);
    input_file.open(input_file_path);
    if (input_file.fail()) {

        cout << "\nПроизошла ошибка при открытии файла " << input_file_path;
    }
    else {
        vector<string> word_array(1);
        string output_string;
        int word_amount = 0;
        fs::path file_path(input_file_path);
        string file_name = file_path.stem().string();
        string analysis_file_name = file_name + " - analysis.txt";
        ofstream analysis_file(analysis_file_name);
        vector<int> word_amount_by_length(0);

        // Составление массива слов с их подсчётом.
        word_array = word_Counting(input_file, output_string, word_amount);

        // Очистка от пустых элементов
        word_array = clear_Empty_Elements(word_array, word_amount);
        //

        // Нахождение количества слов каждой длины
        word_amount_by_length = each_Length_Words(word_array);
        // 

        // Сортировка и вычисление времени
        auto start_time = chrono::high_resolution_clock::now();
        word_array = quick_Sort(word_array);
        auto end_time = chrono::high_resolution_clock::now();
        auto search_time = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        //

        // Вывод в analysis
        input_file.clear();
        input_file.seekg(0, input_file.beg);
        analysis_file << "Введенный текст: " << endl;
        while (getline(input_file, output_string)) {
            analysis_file << output_string << endl;
        }
        analysis_file << "\nВариант 11: латиница, по кол-ву символов в слове, по убыванию, учитывать числа, быстрая сортировка" << endl;
        analysis_file << "Количество слов: " << word_amount + 1 << endl;
        analysis_file << "Время сортировки " << search_time << " миллисекунд" << endl;
        analysis_file << "Статистика (количество слов каждой длины):" << endl;
        for (int i = 0; i < word_amount_by_length.size(); i++) {
            analysis_file << '[' << i + 1 << ']' << " - " << word_amount_by_length[i] << endl;
        }
        analysis_file.close();
        //

        // Вывод в консоль
        input_file.clear();
        input_file.seekg(0, input_file.beg);
        cout << "\nВведенный текст:" << endl;
        while (getline(input_file, output_string)) {
            cout << output_string << endl;
        }
        cout << "\nВариант 11: латиница, по кол-ву символов в слове, по убыванию, учитывать числа, быстрая сортировка" << endl;
        cout << "Количество слов и чисел: " << word_amount + 1 << endl;
        cout << "Время сортировки: " << search_time << " миллисекунд" << endl;
        cout << "Статистика (количество слов каждой длины):" << endl;
        for (int i = 0; i < word_amount_by_length.size(); i++) {
            cout << '[' << i + 1 << ']' << " - " << word_amount_by_length[i] << endl;
        }
        string result_file_name = file_name + " - result.txt";
        ofstream result_file(result_file_name);
        result_file << "Отсортированный массив: " << endl;
        for (int i = 0; i < word_array.size(); i++) {
            result_file << '[' << i << ']' << " - " << word_array[i] << endl;
        }
        result_file.close();
    }
    input_file.close();
    cout << "\n\nНажмите ENTER, чтобы закрыть программу...";
    cin.get();
}