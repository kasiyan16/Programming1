#include <iostream>

int main() {
    setlocale(LC_ALL, "UKR");
    // ��������� ��i��� ��� ����i����� ������ �i����
    int month;

    // �������� ���i�������� ��� �������� ������ �i����
    std::cout << "����i�� ����� �i���� (1-12): ";
    std::cin >> month;

    // �����i�����, �� �������� ����� �i���� �i����
    if (month >= 1 && month <= 12) {
        // ��������� ���� ����
        std::string season;
        if (month >= 3 && month <= 5)
            season = "�����";
        else if (month >= 6 && month <= 8)
            season = "�i��";
        else if (month >= 9 && month <= 11)
            season = "��i��";
        else
            season = "����";

        // �������� ����� �i���� �� ���� ����
        std::cout << "�i���� ����� " << month << " - ";
        switch (month) {
        case 1: std::cout << "�i����"; break;
        case 2: std::cout << "�����"; break;
        case 3: std::cout << "��������"; break;
        case 4: std::cout << "��i����"; break;
        case 5: std::cout << "�������"; break;
        case 6: std::cout << "�������"; break;
        case 7: std::cout << "������"; break;
        case 8: std::cout << "�������"; break;
        case 9: std::cout << "��������"; break;
        case 10: std::cout << "�������"; break;
        case 11: std::cout << "��������"; break;
        case 12: std::cout << "�������"; break;
        }
        std::cout << " �� ���� ����: " << season << std::endl;
    }
    else {
        // �������� ���i�������� ��� ���i���� ��i�
        std::cout << "������������ ����� �i����. ����i�� ����� �i� 1 �� 12." << std::endl;
    }

    return 0;
}
