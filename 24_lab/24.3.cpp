#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
class Rational {
public:
    Rational() : numerator(0), denominator(1) {

    }
    Rational(int numerator, int denominator) {
        int gcd_value = gcd(abs(numerator), abs(denominator));
        this->numerator = numerator / gcd_value;
        this->denominator = denominator / gcd_value;

        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }
    int Numerator() const {
        return numerator;
    }
    int Denominator() const {
        return denominator;
    }
    bool operator==(const Rational& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }
    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

private:
    int gcd(int a, int b) const {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    int numerator;
    int denominator;
};
int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }
    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }
    cout << "OK" << endl;
    return 0;
}

