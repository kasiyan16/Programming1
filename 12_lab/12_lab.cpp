#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char letter;

    do {
        cout << "Введіть літеру (Q або Z для виходу): ";
        cin >> letter;

        if (isalpha(letter)) {
            letter = toupper(letter);
            int digit;

            switch (letter) {
                case 'A': case 'B': case 'C':
                    digit = 2;
                    break;
                case 'D': case 'E': case 'F':
                    digit = 3;
                    break;
                case 'G': case 'H': case 'I':
                    digit = 4;
                    break;
                case 'J': case 'K': case 'L':
                    digit = 5;
                    break;
                case 'M': case 'N': case 'O':
                    digit = 6;
                    break;
                case 'P': case 'R': case 'S':
                    digit = 7;
                    break;
                case 'T': case 'U': case 'V':
                    digit = 8;
                    break;
                case 'W': case 'X': case 'Y':
                    digit = 9;
                    break;
                default:
                    cout << "Введено неправильну літеру. Спробуйте ще раз." << endl;
                    continue;
            }

            cout << "Буква " << letter << " відповідає цифрі " << digit << " на телефоні." << endl;
        } else if (letter != 'Q' && letter != 'Z') {
            cout << "Введено неправильний символ. Спробуйте ще раз." << endl;
        }

    } while (letter != 'Q' && letter != 'Z');

    cout << "Вихід." << endl;

    return 0;
}
