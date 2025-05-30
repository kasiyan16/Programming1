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
int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }
    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }
    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }
    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }
    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }
    {
        const Rational defaultConstructed;



        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
    cout << "OK" << endl;
    return 0;
}

