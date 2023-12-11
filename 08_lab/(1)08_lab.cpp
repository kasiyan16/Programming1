#include <iostream>

// Функція для виконання арифметичних операцій
void Calc(double operand1, char operation, double operand2) {
    double result = (operation == '+') ? operand1 + operand2 :
                    (operation == '-') ? operand1 - operand2 :
                    (operation == '*') ? operand1 * operand2 :
                    (operation == '/' && operand2 != 0) ? operand1 / operand2 :
                    (std::cout << "Помилка: " << ((operation == '/') ? "Ділення на нуль." : "Невідома операція.") << std::endl, 0);

    if (operation != '/' || operand2 != 0)
        std::cout << "Результат дорівнює " << result << std::endl;
}

int main() {
    char choice;

    do {
        // Змінні для зберігання введених даних
        double operand1, operand2;
        char operation;

        // Введення операндів та операції
        std::cout << "Введіть перший операнд, операцію і другий операнд: ";
        std::cin >> operand1 >> operation >> operand2;

        // Виклик функції для виконання операції
        Calc(operand1, operation, operand2);

        // Питання про виконання ще однієї операції
        std::cout << "Виконати ще одну операцію (y/n)? ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
