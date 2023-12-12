#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;
class Rational {
public:
    Rational() : numerator(0), denominator(1) {
        // 
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

ostream& operator<<(ostream& out, const Rational& rational) {
    out << rational.Numerator() << '/' << rational.Denominator();
    return out;
}

istream& operator>>(istream& in, Rational& rational) {
    int numerator = 0, denominator = 1;
    char delimiter;
    in >> numerator >> delimiter >> denominator;
    if (in && delimiter == '/') {
        rational = Rational(numerator, denominator);
    }
    return in;
}
int main() {

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }
    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }
    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }


    }
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }
        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " "
                << r2 << endl;
            return 5;
        }
    }
    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: " << r1 << " " << r2 << " " << r3 << endl;
            return 6;
        }
    }


    cout << "OK" << endl;
    return 0;
}

