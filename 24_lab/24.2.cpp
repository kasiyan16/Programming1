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
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }
    {

        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}

