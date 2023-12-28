#include<iostream>
#include<cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "UKR");
    // Const numbers
    const double r = 5.0;
    const double X_center = 5.0;
    const double Y_center = 5.0;
    // Задаємо значення за допомогою вводу
    double x, y;
    cout << "Введіть точку X: ";
    cin >> x;
    cout << "Введіть точку Y: ";
    cin >> y;
    double R;
    double distance = pow(x - X_center, 2) + pow(y - Y_center, 2);

    // Тут у випадку якщо радіус більше або рівний дистанції з формули
    // виводить що точка знаходиться в колі, в іншому випадку попросить вказати новий X, Y
    if (distance <= r) {
        cout << "Точка лежить в середині кола." << endl;
    }
    else {
        cout << "Точка лежить за межами кола." << endl;
        cout << "Введіть нові координати точки: " << endl;
        cout << "Вкажіть новий X: ";
        cin >> x;
        cout << "Вкажіть новий Y: ";
        cin >> y;
        double distance = pow(x - X_center, 2) + pow(y - Y_center, 2);

        if (distance <= r) {
            cout << "Точка лежить всередині кола." << endl;
        }
        else {
            cout << "Точка лежить за межами кола." << endl;
        }
    }


    return 0;
}