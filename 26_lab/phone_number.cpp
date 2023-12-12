#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;

class PhoneNumber {
private:
    string country_code;
    string city_code;
    string local_number;

public:
    PhoneNumber(const string& international_number) {
        static const regex pattern(R"(^\+(\d+)-(\d+)-(\w+)$)");
        smatch match;
        if (!regex_match(international_number, match, pattern)) {
            throw invalid_argument("���������� ����� �� ��i�����  '+' i ����� ��i����� ���� '-' : " + international_number);
        }
        country_code = match.str(1);
        city_code = match.str(2);
        local_number = match.str(3);
    }

    string GetCityCode() const {
        return city_code;
    }

    string GetLocalNumber() const {
        return local_number;
    }

    string GetInternationalNumber() const {
        return "+" + country_code + "-" + city_code + "-" + local_number;
    }
};

int main() {
    setlocale(LC_ALL, "UKR");
    try {
        PhoneNumber phone1("+38-066-1763");
        cout << phone1.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    try {
        PhoneNumber phone2("+38-066-aaaa");
        cout << phone2.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    try {
        PhoneNumber phone3("+380-66-3830");
        cout << phone3.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    try {
        PhoneNumber phone4("+3-7-aaaa");
        cout << phone4.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    try {
        PhoneNumber phone5("380-66-aaaa");
        cout << phone5.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    try {
        PhoneNumber phone6("+380-66-");
        cout << phone6.GetInternationalNumber() << endl;
    }
    catch (invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
    return 0;
}
