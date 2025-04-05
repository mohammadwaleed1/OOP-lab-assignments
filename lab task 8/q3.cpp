#include <iostream>
#include <vector>
using namespace std;

class BigInteger {
private:
    vector<int> digits; 
    bool negative;     

public:
    BigInteger(){
        negative=true;
    }
    BigInteger(const string& str) {
        negative = (str[0] == '-');
        int startIndex = (negative ? 1 : 0);
        for (int i = str.size() - 1; i >= startIndex; --i) {
            digits.push_back(str[i] - '0');
        }
    }

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            negative = false;
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        result.digits.clear();
        int carry = 0;
        size_t maxSize = max(digits.size(), other.digits.size());

        for (size_t i = 0; i < maxSize || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        result.negative = negative;
        result.normalize();
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        BigInteger result;
        result.digits.clear();
        int borrow = 0;
        size_t maxSize = digits.size();

        for (size_t i = 0; i < maxSize; ++i) {
            int diff = digits[i] - borrow;
            if (i < other.digits.size()) {
                diff -= other.digits[i];
            }

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }

        result.negative = negative;
        result.normalize();
        return result;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& obj) {
        if (obj.negative) os << '-';
        for (auto it = obj.digits.rbegin(); it != obj.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& obj) {
        string str;
        is >> str;
        obj = BigInteger(str);
        return is;
    }
};

int main() {
    BigInteger num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    BigInteger sum = num1 + num2;
    cout << "Sum: " << sum << endl;

    BigInteger diff = num1 - num2;
    cout << "Difference: " << diff << endl;

    return 0;
}
