#include <iostream>
#include <string>

using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    static const double MAX_DAILY_DEPOSIT;
    static const double MAX_DAILY_WITHDRAW;

public:
    Wallet() : balance(0.0), dailyDepositTotal(0.0), dailyWithdrawTotal(0.0) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << " Invalid deposit amount.\n";
            return false;
        }
        if (dailyDepositTotal + amount > MAX_DAILY_DEPOSIT) {
            cout << "❌Deposit failed: Daily deposit limit exceeded.\n";
            return false;
        }
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposit successful. New balance: " << balance << "\n";
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << " Invalid withdrawal amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "withdrawal failed: Insufficient balance.\n";
            return false;
        }
        if (dailyWithdrawTotal + amount > MAX_DAILY_WITHDRAW) {
            cout << " Withdrawal failed: Daily withdrawal limit exceeded.\n";
            return false;
        }
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrawal successful. New balance: " << balance << "\n";
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDepositTotal = 0.0;
        dailyWithdrawTotal = 0.0;
    }
};

const double Wallet::MAX_DAILY_DEPOSIT = 5000.0;
const double Wallet::MAX_DAILY_WITHDRAW = 3000.0;

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(const string& id, const string& userName) : userID(id), name(userName) {}

    void deposit(double amount) {
        cout << "\n[" << name << "] Trying to deposit: " << amount << "\n";
        wallet.deposit(amount);
    }

    void withdraw(double amount) {
        cout << "\n[" << name << "] Trying to withdraw: " << amount << "\n";
        wallet.withdraw(amount);
    }

    void checkBalance() const {
        cout << "[" << name << "] Current balance: " << wallet.getBalance() << "\n";
    }

    void resetLimits() {
        wallet.resetDailyLimits();
        cout << "[" << name << "] Daily limits reset.\n";
    }
};

int main() {
    User user1("U001", "Alice");
    User user2("U002", "Bob");

    user1.deposit(1000);
    user1.withdraw(300);
    user1.checkBalance();

    user2.deposit(6000); 
    user2.deposit(2000);
    user2.withdraw(4000); 
    user2.withdraw(2500);

    user2.checkBalance();

    user2.resetLimits();     
    user2.deposit(3000);
    user2.checkBalance();

    return 0;
}
