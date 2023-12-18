#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int variant = 9;
    const int size = 10;
    double results[size]; // створити масив
    // розрахувати масив
    for (int k = 1; k <= size; ++k) {
        double x = k;
        results[k - 1] = cos(pow(x, 2) + 1) - fabs(sin(2 * x) - 5.76);
    }

    // вивести елементи масиву
    cout << "Еlements: ";
    for (int i = 0; i < size; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    // Другий від'ємний елемент поміняти місцями із третім додатнім
    int secondNegativeIndex = -1;
    int thirdPositiveIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (results[i] < 0) {
            if (secondNegativeIndex == -1) {
                secondNegativeIndex = i;
            } else if (thirdPositiveIndex == -1) {
                thirdPositiveIndex = i;
                break;
            }
        }
    }

    // Обмін значень, якщо індекси знайдено
    if (secondNegativeIndex != -1 && thirdPositiveIndex != -1) {
        double temp = results[secondNegativeIndex];
        results[secondNegativeIndex] = results[thirdPositiveIndex];
        results[thirdPositiveIndex] = temp;

        // вивести змінений масив
        cout << "Modified Elements: ";
        for (int i = 0; i < size; ++i) {
            cout << results[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Insufficient data to perform the swap." << endl;
    }

    return 0;
}
