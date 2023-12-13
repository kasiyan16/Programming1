#include <iostream>
#include <string>

// Структура для представлення інформації про країну
struct Country {
    std::string name;
    int population;
    double area;
};

// Функція для виведення інформації про країну
void printCountry(const Country& country) {
    std::cout << "Назва країни: " << country.name << std::endl;
    std::cout << "Населення: " << country.population << " осіб" << std::endl;
    std::cout << "Площа: " << country.area << " км^2" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    setlocale(LC_ALL, "UKR");

    const int arraySize = 6; // Кількість країн
    Country countries[arraySize]; // Масив об'єктів типу Country

    // Ініціалізація даними
    countries[0] = { "Україна", 44000000, 603500 };
    countries[1] = { "США", 331000000, 9834000 };
    countries[2] = { "Китай", 1440000000, 9597000 };
    countries[3] = { "Індія", 1393000000, 3287000 };
    countries[4] = { "Бразилія", 209000000, 8516000 };
    countries[5] = { "Канада", 104000000, 1002450 };

    // Виведення інформації про всі країни
    std::cout << "Інформація про всі країни:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        printCountry(countries[i]);
    }

    // Виведення країн з населенням більше одного мільярда
    std::cout << "Країни з населенням більше одного мільярда:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        if (countries[i].population > 1000000000) {
            printCountry(countries[i]);
        }
    }

    return 0;
}
