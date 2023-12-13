#include <iostream>
using namespace std;

int main() {
    int sets;
    cout << "Введіть кількість наборів даних: ";
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int crewMembers, passengers;
        double toiletWeight, luggageWeight, fuelGallons;

        // Введення даних від користувача
        cout << "Введіть кількість членів команди: ";
        cin >> crewMembers;

        cout << "Введіть кількість пасажирів: ";
        cin >> passengers;

        cout << "Введіть вагу туалету: ";
        cin >> toiletWeight;

        cout << "Введіть вагу багажу: ";
        cin >> luggageWeight;

        cout << "Введіть кількість палива в галонах: ";
        cin >> fuelGallons;

        // Розрахунок загальної ваги та центра ваги
        double totalWeight = crewMembers * 150 + passengers * 150 + toiletWeight + luggageWeight + fuelGallons * 6;
        double weightCenter = (crewMembers * 200 + passengers * 175 + toiletWeight * 2 + luggageWeight + fuelGallons * 6 * 30) / totalWeight;

        // Виведення результатів
        cout << "Результат для набору " << i + 1 << ":" << endl;
        cout << "Загальна вага: " << totalWeight << " фунтів" << endl;
        cout << "Центр ваги: " << weightCenter << " дюймів від носу літака" << endl;
        cout << endl;
    }

    return 0;
}
