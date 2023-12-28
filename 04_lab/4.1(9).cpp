#include <iostream>

int main() {
    setlocale(LC_ALL, "UKR");
    // ќголошуЇмо змiнну дл€ зберiганн€ номера мiс€ц€
    int month;

    // ¬иводимо повiдомленн€ про введенн€ номера мiс€ц€
    std::cout << "¬ведiть номер мiс€ц€ (1-12): ";
    std::cin >> month;

    // ѕеревiр€Їмо, чи введений номер мiс€ц€ вiрний
    if (month >= 1 && month <= 12) {
        // ¬изначаЇмо пору року
        std::string season;
        if (month >= 3 && month <= 5)
            season = "весна";
        else if (month >= 6 && month <= 8)
            season = "лiто";
        else if (month >= 9 && month <= 11)
            season = "осiнь";
        else
            season = "зима";

        // ¬иводимо назву мiс€ц€ та пору року
        std::cout << "ћiс€ць номер " << month << " - ";
        switch (month) {
        case 1: std::cout << "сiчень"; break;
        case 2: std::cout << "лютий"; break;
        case 3: std::cout << "березень"; break;
        case 4: std::cout << "квiтень"; break;
        case 5: std::cout << "травень"; break;
        case 6: std::cout << "червень"; break;
        case 7: std::cout << "липень"; break;
        case 8: std::cout << "серпень"; break;
        case 9: std::cout << "вересень"; break;
        case 10: std::cout << "жовтень"; break;
        case 11: std::cout << "листопад"; break;
        case 12: std::cout << "грудень"; break;
        }
        std::cout << " та пора року: " << season << std::endl;
    }
    else {
        // ¬иводимо повiдомленн€ про невiрний ввiд
        std::cout << "Ќеправильний номер мiс€ц€. ¬ведiть число вiд 1 до 12." << std::endl;
    }

    return 0;
}
