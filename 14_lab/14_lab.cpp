#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
..................
using namespace std;

int main() {
    const int variantNumber = 9;
    double results[11];

    // Fill the array with results for each year
    for (int k = 0; k <= 10; ++k) {
        double x = k;
        double result = cos(pow(x, 2) + 1) - fabs(sin(2 * x) - 5.76);
        results[k] = result;
    }

    // Display the table
    cout << "+----------------------+ " << endl;
    cout << "| Year | Result         | " << endl;
    cout << "+----------------------+ " << endl;
    for (int i = 0; i < 11; ++i) {
        cout << "| " << 2000 + i << " | " << results[i] << "     | " << endl;
    }
    cout << "+----------------------+ " << endl;

    // Find the largest result
    double maxResult = -numeric_limits<double>::infinity();
    int yearWithMaxResult = 2000;

    for (int i = 0; i < 11; ++i) {
        if (results[i] > maxResult) {
            maxResult = results[i];
            yearWithMaxResult = 2000 + i;
        }
    }

    // Display results
    cout << "The largest result is: " << maxResult << " in year " << yearWithMaxResult << endl;

    return 0;
}
