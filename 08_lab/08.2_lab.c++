#include <iostream>

void PrintSymbol(char symbol, int count) {
    if (count != 0) {
        for (int i = 0; i < count; ++i)
            std::cout << symbol;
        std::cout << std::endl;
    } else {
        std::cout << "Помилка: другий аргумент повинен бути не рівний нулю." << std::endl;
    }
}

int main() {
    char symbol;
    int count;

    std::cout << "Введіть символ: ";
    std::cin >> symbol;

    std::cout << "Введіть ціле число (не рівне нулю): ";
    std::cin >> count;

    PrintSymbol(symbol, count);

    return 0;
}
