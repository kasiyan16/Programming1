#pragma once

#include <string>

using namespace std;

class PhoneNumber {
public:
    PhoneNumber(const string& international_number) {
        static const regex pattern(R"(^\+(\d+)-(\d+)-(\w+)$)");
        smatch match;
        if (!regex_match(international_number, match, pattern)) {
            throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
        }
        country_code = match.str(1);
        city_code = match.str(2);
        local_number = match.str(3);
    }

    string GetCountryCode() const {
        return country_code;
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
private:
    string country_code;
    string city_code;
    string local_number;
};