#include <iostream>
#include <cmath>

// Функція з варіанту
double myFunction(double x) {
    // Замініть це виразом із вашого варіанту
    return 9.2 * cos(2 * x) - fabs(sin(x) / 1.1);
}

int main() {
    const int k_values[] = {1, 2, 3, 4};
    const int n_values[] = {1, 2, 3, 4};

    // Виведемо заголовок таблиці
    std::cout << "№ п/п\tfn(x)\n";

    int count = 1;

    // Проходимо по комбінаціях k і n
    for (int k : k_values) {
        for (int n : n_values) {
            // Обчислюємо fn(x) для кожної комбінації
            double result = myFunction(k + 20 * n + sin(k + 21 * n));

            // Виводимо результат у вигляді таблиці
            std::cout << count++ << "\t" << result << std::endl;
        }
    }

    return 0;
}
