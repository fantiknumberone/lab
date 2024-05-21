#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для реверса букв в каждом слове строки
string reverseWordsInString(const string& str) {
    stringstream ss(str);
    string word;
    string reversedString;
    
    // Разбиваем строку на слова и реверсируем каждое слово
    while (ss >> word) {
        reverse(word.begin(), word.end());
        if (!reversedString.empty()) {
            reversedString += " ";
        }
        reversedString += word;
    }
    
    return reversedString;
}

int main() {
    ofstream outFile("input.txt"); // Создаем файл для записи

    if (!outFile) {
        cerr << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    // Пример данных для записи в файл 
    vector<string> lines = {
        "hello",
        "world",
        "turururururur"
    };

    // Запись строк в файл
    for (const auto& line : lines) {
        outFile << line << endl;
    }
// fopen('temp.txt', );
    outFile.close(); // Закрываем файл после записи

    // Теперь читаем файл, обрабатываем строки и записываем в новый файл
    ifstream inFile("input.txt");
    ofstream outProcessedFile("output.txt");

    if (!inFile || !outProcessedFile) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string reversedLine = reverseWordsInString(line);
        outProcessedFile << reversedLine << endl;
    }

    inFile.close();
    outProcessedFile.close();

    cout << "Обработка завершена. Проверьте файл output.txt." << endl;

    return 0;
}