#include <iostream>
using namespace std;

// Завдання 1 - Конвертація температури
void PrintTemp() {
    cout << "Будь-ласка, введіть температуру у градусах за Цельсієм: ";
    double celsius;
    cin >> celsius;

    double fahrenheit = 1.8 * celsius + 32.0;

    cout << celsius << " градусів за Цельсієм дорівнює " << fahrenheit << " градусів за Фаренгейтом" << endl;
    cout << "Формула перерахунку: Фаренгейт = 1,8 * Цельсій + 32,0" << endl;
}

// Завдання 2 - Обчислення середнього гармонійного
double PrintGarm() {
    double num1, num2;

    do {
        cout << "Введіть два числа (хоча б одне не рівне нулю): ";
        cin >> num1 >> num2;
    } while (num1 == 0 && num2 == 0);

    double harmonicMean = 2.0 / (1.0 / num1 + 1.0 / num2);

    cout << "Середнє гармонійне для " << num1 << " і " << num2 << " дорівнює " << harmonicMean << endl;

    return harmonicMean;
}

// Завдання 3 - Обчислення факторіалу
int PrintFactorial() {
    int number;
    cout << "Введіть ціле число для обчислення факторіалу: ";
    cin >> number;

    if (number < 0) {
        cout << "Факторіал не визначений для від'ємних чисел." << endl;
        return 0;
    }

    int factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }

    cout << "Факторіал " << number << " дорівнює " << factorial << endl;

    return factorial;
}

int main() {
    PrintTemp();
    double result = PrintGarm();
    int factorialResult = PrintFactorial();

    return 0;
}
