#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Відкриваємо файл для зчитування
    std::ifstream file("myfile.dat");

    // Перевіряємо, чи файл вдалося відкрити
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;  // Повертаємо код помилки
    }

    // Змінна для зберігання рядка з файлу
    std::string line;

    // Змінна для зберігання кількості входжень "!="
    int count = 0;

    // Зчитуємо рядок з файлу
    while (std::getline(file, line)) {
        // Пошук входжень "!=" у рядку
        size_t pos = line.find("!=");
        while (pos != std::string::npos) {
            // Знайдено "!="
            count++;
            // Продовжуємо пошук в іншій частині рядку
            pos = line.find("!=", pos + 2);
        }
    }

    // Виводимо кількість входжень "!="
    std::cout << "Кількість входжень \"!=\": " << count << std::endl;

    // Закриваємо файл
    file.close();

    return 0;
}
