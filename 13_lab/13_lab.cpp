#include <iostream>
#include <cmath>

using namespace std;

// Приклад функції fi+8(x) з варіанту
double function(int i, double x) {
    return sin(i) + 8 * x;
}

int main() {
    int i; // Номер варіанту
    cout << "Введіть номер варіанту: ";
    cin >> i;

    double h = 0.1 * i; // Крок
    double x;
    int n = 10; // Кількість точок для табуляції

    cout << "Таблиця значень функції:" << endl;
    cout << "x\t\tf(x)" << endl;

    for (int k = 0; k <= n; k++) {
        x = k * h;
        cout << x << "\t\t" << function(i, x) << endl;
    }

    // Пошук даних відповідно до вашого варіанту
    double maxValue = function(i, 0);
    double firstValue = function(i, 0);

    for (int k = 1; k <= n; k++) {
        x = k * h;
        double currentValue = function(i, x);

        if (currentValue > maxValue) {
            maxValue = currentValue;
        }

        if (k == 1) {
            firstValue = currentValue;
        }
    }

    // Виведення результатів
    cout << "\nМаксимальне значення: " << maxValue << endl;
    cout << "Перше значення: " << firstValue << endl;
    cout << "Модуль різниці: " << abs(maxValue - firstValue) << endl;

    return 0;
}
