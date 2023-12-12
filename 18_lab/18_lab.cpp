#include <iostream>
#include <string>

// Структура для опису автомобілів
struct Car {
    std::string model;
    int year;
    double price;
    std::string color;
};

int main() {
    const int arraySize = 6; // Розмір масиву

    // Створення масиву з шести елементів структури Car
    Car cars[arraySize] = {
        {"Toyota Camry", 2000, 5000.0, "Blue"},
        {"Honda Accord", 2005, 7000.0, "Red"},
        {"Ford Mustang", 2001, 6000.0, "Red"},
        {"Chevrolet Malibu", 2003, 5500.0, "Silver"},
        {"Nissan Altima", 2008, 8000.0, "Black"},
        {"BMW 3 Series", 2001, 10000.0, "Red"}
    };

    // Виведення інформації про всі автомобілі
    std::cout << "Information about all cars:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Model: " << cars[i].model << ", Year: " << cars[i].year
                  << ", Price: " << cars[i].price << ", Color: " << cars[i].color << std::endl;
    }

    // Пошук і виведення моделей червоного кольору, випущених в 2001 році
    std::cout << "\nRed cars released in 2001:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        if (cars[i].color == "Red" && cars[i].year == 2001) {
            std::cout << cars[i].model << std::endl;
        }
    }

    return 0;
}
