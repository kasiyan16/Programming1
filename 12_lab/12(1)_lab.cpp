#include <iostream>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "UKR");

    char input;

    do {
        cout << "Введіть літеру: ";
        cin >> input;
        input = toupper(input); // Перетворення на велику літеру

        if (isalpha(input)) {
            int digit;

            // Визначення цифри на клавіатурі телефона за літерою
            if (input >= 'A' && input <= 'C') {
                digit = 2;
            }
            else if (input >= 'D' && input <= 'F') {
                digit = 3;
            }
            else if (input >= 'G' && input <= 'I') {
                digit = 4;
            }
            else if (input >= 'J' && input <= 'L') {
                digit = 5;
            }
            else if (input >= 'M' && input <= 'O') {
                digit = 6;
            }
            else if (input >= 'P' && input <= 'S') {
                digit = 7;
            }
            else if (input >= 'T' && input <= 'U') {
                digit = 8;
            }
            else if (input >= 'W' && input <= 'Y') {
                digit = 9;
            }
            else {
                cout << "Невірна літера. Введіть Q або Z, щоб завершити." << endl;
                continue;
            }

            cout << "Літера " << input << " відповідає цифрі " << digit << " на клавіатурі телефона." << endl;
        }
        else if (input != 'Q' && input != 'Z') {
            cout << "Невірна літера
