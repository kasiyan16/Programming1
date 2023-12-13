#include <iostream>
#include <string>

using namespace std;

// Function to get the full name of a U.S. state based on its abbreviation
string getStateName(const string& abbreviation) {
    switch (abbreviation[0]) {
    case 'A':
        if (abbreviation == "AL") return "Alabama";
        if (abbreviation == "AK") return "Alaska";
        if (abbreviation == "AZ") return "Arizona";
        if (abbreviation == "AR") return "Arkansas";
        break;
    case 'C':
        if (abbreviation == "CA") return "California";
        if (abbreviation == "CO") return "Colorado";
        if (abbreviation == "CT") return "Connecticut";
        break;
    // Add more cases for other states as needed
    default:
        break;
    }

    return "";  // Return an empty string if the abbreviation is not recognized
}

int main() {
    setlocale(LC_ALL, "UKR");  // Set the locale to Ukrainian
    string abbreviation;

    while (true) {
        cout << "Введіть скорочену назву штату (або 'exit' для виходу): ";
        cin >> abbreviation;

        if (abbreviation == "exit") {
            break;
        }

        string stateName = getStateName(abbreviation);

        if (!stateName.empty()) {
            cout << "Повна назва штату: " << stateName << endl;
        }
        else {
            cout << "Помилка: Невідома або неправильна скорочена назва. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
