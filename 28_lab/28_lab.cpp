#include <iostream>
#include <string>
using namespace std;

// Прототипи функцій для відправлення SMS та Email
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);

// Абстрактний базовий клас
class INotifier {
public:
    virtual void Notify(const string& message) const = 0;
};

// Клас для надсилання SMS-повідомлень
class SmsNotifier : public INotifier {
public:
    SmsNotifier(const string& phoneNumber) : phone(phoneNumber) {}

    void Notify(const string& message) const override {
        SendSms(phone, message);
    }

private:
    string phone;
};

// Клас для надсилання Email-повідомлень
class EmailNotifier : public INotifier {
public:
    EmailNotifier(const string& emailAddress) : email(emailAddress) {}

    void Notify(const string& message) const override {
        SendEmail(email, message);
    }

private:
    string email;
};

// Функція для відправлення SMS
void SendSms(const string& number, const string& message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

// Функція для відправлення Email
void SendEmail(const string& email, const string& message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}

// Функція для сповіщення
void Notify(const INotifier& notifier, const string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms{"+38-067-777-77-77"};
    EmailNotifier email{"lab28-final@pnu.edu.ua"};

    Notify(sms, "I am learning C++");
    Notify(email, "and I want to be successful");

    return 0;
}
