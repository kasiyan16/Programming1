#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int i = 9;//номер варіанту
	int const xA = 0; 	int const  yA = 0; //A(0;0)
	float const xB = i; 	float const yB = i - 1; //B(5;4)
	float const xC = -i;	float const yC = i + 1; //C(-5;6)
    
	int a, b, c;

	float d, x, y, p, S, ha, hb, hc, Wa, Wb, Wy, R, r, m, AB, BC, CA;

	AB = sqrt(pow(xB-xA, 2) + (yB - yA, 2));
	BC = sqrt(pow(xC -xB, 2) + pow(yC - yB, 2));
	CA = sqrt(pow(xA-xC, 2) + pow(yA - yC, 2));
	a = AB;
	b = BC;
	c = CA;
	x = (xA + xB) / 2;
	y = (yA + yB) / 2;
	p = (a + b + c) /2; // perimetr
    S = sqrt((p * (p - a) * (p - b) * (p - c)));
	R = (a*b*c) / 4*S;
	r = S/p; //радіус описаного кола
    ha = (2 * S) / a; // висота а

    cout << "Height ha = "<< fixed << setprecision(2) << ha << endl; 
    cout << "The radius of the circle = " << fixed << setprecision(2) << r << endl; 
}
