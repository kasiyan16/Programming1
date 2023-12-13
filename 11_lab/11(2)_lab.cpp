#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "UKR");

    char workType;
    double x, payment, tax, netPayment;

    // Введення типу роботи
    std::cout << "Введіть тип роботи (A, B або C): ";
    std::cin >> workType;

    // Введення значення x
    std::cout << "Введіть x: ";
    std::cin >> x;

    // Обчислення оплати за роботу
    switch (workType) {
    case 'A':
        payment = 100 * std::fabs(sin(12 * x) * cos(fabs(2 * x)) / 3) + 4.21 + 50;
        break;
    case 'B':
        payment = 150 * std::cos(pow(x, 3) / 2.1 + cos(pow(x, 2) / 1.1 - 8.3 * sin(3 * x + 1))) + 100;
        break;
    case 'C':
        payment = 200 * std::sin(pow(x, 2)) - cos(pow(x, 3)) - sin(x) + 5.2 + 135;
        break;
    default:
        std::cout << "Невірний тип роботи. Оберіть A, B або C." << std::endl;
        return 1; // Повернення коду помилки
    }

    // Обчислення податку
    if (workType == 'A') {
        tax = 0.1 * payment;
    } else if (workType == 'B') {
        tax = 0.15 * payment;
    } else {
        tax = 0.2 * payment;
    }

    netPayment = payment - tax;

    // Виведення результатів
    std::cout << "Сума оплати: " << payment << std::endl;
    std::cout << "Сума податку: " << tax << std::endl;
    std::cout << "Чиста сума: " << netPayment << std::endl;

    return 0;
}
