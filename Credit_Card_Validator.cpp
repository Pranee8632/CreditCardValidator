#include <iostream>
#include <string>

class CreditCardValidator {
public:
    CreditCardValidator(const std::string& ccNumber) : ccNumber(ccNumber) {}

    bool validate() {
        if (!isNumberString(ccNumber)) {
            std::cout << "Bad input! ";
            return false;
        }

        int len = ccNumber.length();
        int doubleEvenSum = 0;

        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccNumber[i] - '0') * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - '0');
        }

        return (doubleEvenSum % 10 == 0);
    }

private:
    std::string ccNumber;

    bool isNumberString(const std::string& s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] < '0' || s[i] > '9')
                return false;
        }
        return true;
    }
};

int main() {
    std::string ccNumber;

    std::cout << "This program uses the Luhn Algorithm to validate a CC number." << std::endl;
    std::cout << "You can enter 'exit' anytime to quit." << std::endl;

    while (true) {
        std::cout << "Please enter a CC number to validate: ";
        std::cin >> ccNumber;

        if (ccNumber == "exit")
            break;

        CreditCardValidator validator(ccNumber);
        bool isValid = validator.validate();

        std::cout << (isValid ? "Valid!" : "Invalid!") << std::endl;
    }

    return 0;
}
