#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{   
    float pi = 3.14;
    float r , S, V;
    cout << "Input your Radius: ";
    cin >> r;
    S = 4 * pi * pow(r , 2);
    V = 4  * pi * pow(r, 3);

    cout << "Ваша площа = "<< fixed << setprecision(2) << S << endl; 
    cout << "Радіус вписаного кола = " << fixed << setprecision(2) << V << endl; 
}
