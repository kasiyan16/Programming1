#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // Відкриття вхідного та вихідного файлів
    std::ifstream inputFile("/c kasiyan");
    std::ofstream outputFile("github");

    // Перевірка, чи файли вдалося відкрити
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    // Зчитування дійсних чисел з вхідного файлу у вектор
    std::vector<double> numbers;
    double number;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    // Сортування чисел в порядку: додатні, нульові, від'ємні
    std::sort(numbers.begin(), numbers.end(), [](double a, double b) {
        if (a >= 0 && b < 0) {
            return true;
        } else if (a >= 0 && b >= 0) {
            return a < b;
        } else {
            return false;
        }
    });

    // Запис відсортованих чисел у вихідний файл
    for (const double& num : numbers) {
        outputFile << num << " ";
    }

    // Закриття файлів
    inputFile.close();
    outputFile.close();

    std::cout << "File successfully sorted and saved to github." << std::endl;

    return 0;
}
