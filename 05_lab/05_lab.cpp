#include <iostream>

// Використовуємо вбудований тип bool для логічних значень
typedef bool Boolean;

// Функція для перевірки оцінок і виведення результату
void checkExamResults(long studentID, int grades[]) {
    // Перевірка на від'ємні оцінки
    for (int i = 0; i < 4; ++i) {
        if (grades[i] < 0) {
            std::cout << "Помилка: Оцінка не може бути від'ємною." << std::endl;
            return;
        }
    }

    // Обчислення середньої оцінки
    double average = (grades[0] + grades[1] + grades[2] + grades[3]) / 4.0;

    // Перевірка на успішне складання екзамену
    bool examPassed = (average >= 3);

    // Виведення результату
    std::cout << "Ідентифікаційний номер студента: " << studentID << std::endl;
    std::cout << "Середня оцінка: " << average << std::endl;

    if (examPassed) {
        std::cout << "Екзамен складено " << (average < 4 ? "задовільно." : (average < 5 ? "добре." : "відмінно.")) << std::endl;
    } else {
        std::cout << "Екзамен не складено." << std::endl;
    }
}

int main() {
    // Вхідні дані
    long studentID;
    int grades[4];

    // Зчитування вхідних даних
    std::cout << "Введіть ідентифікаційний номер студента: ";
    std::cin >> studentID;

    std::cout << "Введіть чотири екзаменаційні оцінки: ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> grades[i];
    }

    // Виклик функції для перевірки та виведення результату
    checkExamResults(studentID, grades);

    return 0;
}