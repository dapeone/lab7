#include <iostream>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

int main() {
    ifstream inputFile("text.txt");

    map<char, int> one; // Для хранения частоты букв
    map<string, int> pair; // Для хранения двубуквенных сочетаний
    char prevCh = '\0'; // Для хранения предыдущего символа
    char ch;

    while (inputFile.get(ch)) {
        if (isalpha(ch)) { // Функция isalpha проверяет, является ли данный символ алфавитным.
            one[ch]++;
            if (prevCh) {
                pair[string(1, prevCh) + ch]++; // string(1, prevCh) - повторение символа prevCh 1 раз
            }
            prevCh = ch;
        } else {
            prevCh = '\0'; // Сброс, если символ не буква
        }
    }

    // Вывод результатов
    for (const auto& letter : one) {
        cout << letter.first << ": " << letter.second << endl;
    }
    for (const auto& letters : pair) {
        cout << letters.first << ": " << letters.second << endl;
    }

    return 0;
}