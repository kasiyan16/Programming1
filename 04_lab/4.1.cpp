#include<iostream>
#include<cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "UKR");
    // Const numbers
    const double r = 5.0;
    const double X_center = 5.0;
    const double Y_center = 5.0;
    // ������ �������� �� ��������� �����
    double x, y;
    cout << "������ ����� X: ";
    cin >> x;
    cout << "������ ����� Y: ";
    cin >> y;
    double R;
    double distance = pow(x - X_center, 2) + pow(y - Y_center, 2);

    // ��� � ������� ���� ����� ����� ��� ����� ��������� � �������
    // �������� �� ����� ����������� � ���, � ������ ������� ��������� ������� ����� X, Y
    if (distance <= r) {
        cout << "����� ������ � ������� ����." << endl;
    }
    else {
        cout << "����� ������ �� ������ ����." << endl;
        cout << "������ ��� ���������� �����: " << endl;
        cout << "������ ����� X: ";
        cin >> x;
        cout << "������ ����� Y: ";
        cin >> y;
        double distance = pow(x - X_center, 2) + pow(y - Y_center, 2);

        if (distance <= r) {
            cout << "����� ������ �������� ����." << endl;
        }
        else {
            cout << "����� ������ �� ������ ����." << endl;
        }
    }


    return 0;
}