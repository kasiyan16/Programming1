#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the distance between two points
double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to check if a point lies on the given curve
bool pointOnCurve(double x, double y) {
    // Equation of the curve: 9 * cos(x + 1) = |sin(2x) - 5.76|
    double curveValue = 9 * cos(x + 1);
    double absoluteValue = fabs(sin(2 * x) - 5.76);

    return curveValue == absoluteValue;
}

int main() {
    double x1, y1, x2, y2, radius;

    // Inputting coordinates of two points and radius of the circle
    cout << "Enter the radius of the curve: ";
    cin >> radius;

    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    // Checking if points lie on the given curve
    if (pointOnCurve(x1, y1) && pointOnCurve(x2, y2)) {
        cout << "The points lie on the curve with radius " << radius << " and center at the origin." << endl;
    } else {
        cout << "The points do not lie on the curve with radius " << radius << " and center at the origin." << endl;
    }

    return 0;
}
