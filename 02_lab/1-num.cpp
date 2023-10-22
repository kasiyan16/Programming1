#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
float first, second, third, fore;
float Mileage, Mileage2;
cout << "How many liters of gasoline did you fill up? (Write 11.7)" << endl;
cin >> first;
cout << "How many liters of gasoline did you fill up the second time? (Write 14.3)" << endl;
cin >> second;
cout << "How many liters of gasoline did you fill up for the third time? (Write 12.2)" << endl; 
cin >> third;
cout << "How many liters of gasoline did you fill up last time? (Write 8.5)" << endl;
cin >> fore;
cout << "Mileage before trip (67308)" << endl;
cin >> Mileage;
cout << "Mileage after trip (68750)" << endl;
cin >> Mileage2;

float total_liters = first + second + third + fore; 
float road_distance = Mileage2 - Mileage; 
float result = road_distance / total_liters; //Підрахунок для виводу
cout << "Mileage after trip (68750)" << endl;
cout << "Your car travels  "<< fixed << setprecision(2) << result << " km per liter" << endl; //Скорочення до 2ух знаків після коми.

}
