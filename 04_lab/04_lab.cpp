#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    // Input values for x, a, b, c, d
    double x, a, b, c, d;
    cout << "Enter x, a, b, c, d: ";
    cin >> x >> a >> b >> c >> d;

    // Calculate values of phi and omega
    double i = 9;
    double phi = tan(i + a) - log(i + 1) / fabs(b + 7);
    double omega = c * 5 * sqrt(pow(i, 2) + d * exp(1.3));

    // Calculate the value of y
    double y = (i < 10) ? i + 2 * phi : i + 3 * omega;

    // Output the result to the console
    cout << "Value of y: " << y << endl;

    // Write the result to a file
    ofstream outFile("output.txt");
    outFile << "Value of y: " << y << endl;
    outFile.close();

    return 0;
}