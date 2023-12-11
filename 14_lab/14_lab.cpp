#include <iostream>

int main() {
    const int numYears = 11; // Кількість років
    int year = 2000; // Початковий рік
    int profit[11]; // Масив прибутку на кожний рік

    // Заповнення масиву прибутку за кожен рік
    for (int i = 0; i < numYears; i++) {
        profit[i] = 100 * i + 9 * i * i;
    }

    // Виведення таблиці прибутку
    std::cout << "Year\tProfit\n";
    for (int i = 0; i < numYears; i++) {
        std::cout << year++ << "\t" << profit[i] << std::endl;
    }

    // Знайдення суми збитків та найбільшого прибутку
    int sumOfLosses = 0;
    int maxProfit = profit[0];

    for (int i = 0; i < numYears; i++) {
        if (profit[i] < 0) {
            sumOfLosses += profit[i];
        }

        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
        }
    }

    // Виведення результатів
    std::cout << "Sum of Losses: " << sumOfLosses << std::endl;
    std::cout << "Max Profit: " << maxProfit << std::endl;

    return 0;
}
