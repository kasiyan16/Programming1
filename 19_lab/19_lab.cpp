#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double customFunction(double x) {
    return cos(pow(x, 2) + 1) - abs(sin(2 * x) - 5.76);
}

int main() {
    const int size = 4;

    double matrix[size][size];

    for (int n = 0; n < size; ++n) {
        for (int k = 0; k < size; ++k) {
            double a = customFunction(n * 13.4) * customFunction(abs(k + 1)) * customFunction(pow(k + 1, 2) - 2.25) +
                       customFunction(sin(k + 1)) * abs(customFunction(cos(pow(n + 1, 2) - 3.8))) / 4.5 - 9.7 * customFunction(n + 1 - 3.1);
            matrix[n][k] = a;
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Calculate the sum of diagonal elements and count of negative elements
    double diagonalSum = 0.0;
    int negativeCount = 0;

    for (int i = 0; i < size; ++i) {
        diagonalSum += matrix[i][i]; // Sum of diagonal elements

        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] < 0) {
                negativeCount++;
            }
        }
    }

    // Output the results
    cout << "Sum of diagonal elements: " << diagonalSum << endl;
    cout << "Count of negative elements: " << negativeCount << endl;

    return 0;
}
