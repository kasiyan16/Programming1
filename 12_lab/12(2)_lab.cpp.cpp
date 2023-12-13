#include <iostream> 
#include <cmath> 
using namespace std;

int main()
{
    double z, a = 0;
    double b = 1;
    int i = 9;
    int k = i;
    double x = i;


    do {
        a += 2 * sin(x) * sin(2 * x - 1.5) * cos(2 * x + 1.5) - 6;
        k++;
    } while (k < i + 5);
    do {
        b *= fabs(cos(pow(x, 2) - 0.51)) * sin(3 * x - 4) - 4.44;
        k++;
    } while (k < i + 8);
    z = pow(a * b, 0.25);
    cout << "i = " << i << " a = " << a << " b = " << b << " z = " << int(z) << endl;
    return 0;
}