#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    const int maxSize = 1000;
    char inputString[maxSize];

    // Ввід рядка
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    int length =strlen(inputString);

    // Проходження по рядку
    for (int i = 0; i < length; ++i) {
        // Знаходження початку слова
        if (std::isalpha(inputString[i])) {
            int wordStart = i;

            // Знаходження кінця слова
            while (std::isalpha(inputString[i])) {
                ++i;
            }

            int wordEnd = i - 1;

            // Знаходження іншого слова, що починається з тієї ж літери
            int j = i;
            while (j < length && !std::isalpha(inputString[j])) {
                ++j;
            }

            int nextWordStart = j;

            // Якщо є ще слово
            if (nextWordStart < length && std::tolower(inputString[wordStart]) == std::tolower(inputString[nextWordStart])) {
                // Обмін місцями словами
                for (int k = wordStart; k <= wordEnd; ++k) {
                    char temp = inputString[k];
                    inputString[k] = inputString[nextWordStart + k - wordStart];
                    inputString[nextWordStart + k - wordStart] = temp;
                }

                // Пропуск решти слова
                i = nextWordStart;
            }
        }
    }

    // Вивід результату
    std::cout << "Result: " << inputString << std::endl;

    return 0;
}
