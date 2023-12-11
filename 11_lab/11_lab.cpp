#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int variant;
    char stateAbbreviation;

    cout << "Enter variant (1-50): ";
    cin >> variant;

    cout << "Enter state abbreviation (two letters): ";
    cin >> stateAbbreviation;

    double result, taxRate;

    if (stateAbbreviation == 'A') goto typeA;
    if (stateAbbreviation == 'B') goto typeB;
    if (stateAbbreviation == 'C') goto typeC;

    cout << "Invalid state abbreviation." << endl;
    return 1;

typeA:
    result = 100 * fabs(sin(variant + 2) + 50);
    taxRate = 0.10;
    goto printResults;

typeB:
    result = 150 * fabs(sin(variant + 3) + 100);
    taxRate = 0.15;
    goto printResults;

typeC:
    result = 200 * fabs(sin(variant + 4) + 135);
    taxRate = 0.20;

printResults:
    double tax = result * taxRate;
    double netPay = result - tax;

    cout << "Amount: " << result << endl;
    cout << "Tax amount: " << tax << endl;
    cout << "Amount after tax: " << netPay << endl;

    return 0;
}
