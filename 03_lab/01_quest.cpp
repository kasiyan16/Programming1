#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double mass, velocity, height, kinetic_energy, potential_energy;

    // Введення маси тіла
    cout << "Введіть масу тіла (m, кг): ";
    cin >> mass;

    // Введення швидкості тіла
    cout << "Введіть швидкість тіла (v, м/с): ";
    cin >> velocity;

    // Введення висоти
    cout << "Введіть висоту (h, м): ";
    cin >> height;

    // Обчислення кінетичної енергії (E = 0.5 * m * v^2)
    kinetic_energy = 0.5 * mass * pow(velocity, 2);

    // Обчислення потенціальної енергії (P = m * g * h, де g - прискорення вільного падіння)
    const double g = 9.81;  // приблизне значення прискорення вільного падіння на Землі
    potential_energy = mass * g * height;

    // Виведення результатів
    cout << "Кінетична енергія (E): " << kinetic_energy << " джоулів" << endl;
    cout << "Потенціальна енергія (P): " << potential_energy << " джоулів" << endl;

    return 0;
}
