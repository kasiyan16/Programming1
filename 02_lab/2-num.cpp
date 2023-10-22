#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int mark1, mark2, mark3;
	float coeff1, coeff2, coeff3;
	cout << "First mark of student" << endl;
	cin >> mark1;
	cout << "Coefficient for first estimate" << endl;
	cin >> coeff1;
	cout << "Second mark of student" << endl;
	cin >> mark2;
	cout << "Coefficient for second estimate" << endl; 
	cin >> coeff2;
	cout << "Third mark of student" << endl;
	cin >> mark3;
	cout << "Coefficient for third estimate" << endl;
	cin >> coeff3;
	float sum = coeff1 + coeff2 + coeff3; //сумма коеффіціентів
	float result = (mark1*coeff1 + mark2*coeff2 + mark3*coeff3) / sum; //середня вагова оцінка
	cout <<"Weighted average score: " << fixed << setprecision(2) << result <<endl; //виводжу округлений результат
}
