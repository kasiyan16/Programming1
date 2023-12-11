#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Отримання номера варіанта
    int variant = 9; // Ваш номер варіанту
    const int size = 10; // Розмір масиву

    // Створення динамічного масиву
    int* array = new int[size];

    // Ініціалізація масиву за умовою
    for (int i = 0; i < size; i++) {
        array[i] = variant + 10 * (i + 1);
    }

    // Виведення початкового масиву
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Заміна другого від'ємного елемента із третім додатнім
    int countNegative = 0;
    int countPositive = 0;
    int indexNegative = -1;
    int indexPositive = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            countNegative++;
            if (countNegative == 2) {
                indexNegative = i;
            }
        } else if (array[i] > 0) {
            countPositive++;
            if (countPositive == 3) {
                indexPositive = i;
            }
        }
    }

    // Обмін значень
    if (indexNegative != -1 && indexPositive != -1) {
        int temp = array[indexNegative];
        array[indexNegative] = array[indexPositive];
        array[indexPositive] = temp;
    }

    // Виведення відредагованого масиву
    cout << "Масив після обміну:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Звільнення пам'яті, виділеної для динамічного масиву
    delete[] array;

    return 0;
}
