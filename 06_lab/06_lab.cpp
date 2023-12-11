#include <iostream>
#include <iomanip>

int main() {
    double initialMeasure = 291.0;
    double step = 3.24;
    int rowCount = 10;

    std::cout << std::setw(15) << "Міра" << std::setw(15) << "Літри" << std::endl;

    while (rowCount--) {
        std::cout << std::setw(15) << initialMeasure << std::setw(15) << initialMeasure * 17.68 << std::endl;
        initialMeasure += step;
    }

    return 0;
}
