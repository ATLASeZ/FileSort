#include <iostream>
#include <fstream>
#include <istream>
#include <random>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

// Функция проверки открытия файла для записи
bool IsFileOpen(ofstream& file) {
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;

        return false;
    }
    else {
        cout << "Файл успешно открыт!" << endl;

        return true;
    }
}

// Функция проверки открытия файла для чтения
bool IsFileOpen(ifstream& file) {
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;

        return false;
    }
    else {
        cout << "Файл успешно открыт!" << endl;

        return true;
    }
}

// Функция создания файла со случайным массивом чисел
bool CreateFileWithRandomNumbers(const string& fileName, const int numbersCount, const int maxNumerValue) {
    ofstream file;
    file.open(fileName);

    IsFileOpen(file);

    std::random_device randomDevice;
    std::mt19937 generation(randomDevice());
    std::uniform_int_distribution<> distribution(0, maxNumerValue);

    for (int i = 0; i < numbersCount; ++i) {
        file << distribution(generation) << " ";
    }

    file.close();

    return true;
}