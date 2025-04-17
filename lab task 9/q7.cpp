#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
    }
    virtual void displaydata() {
        cout << "Name: " << name << endl;
    }
    virtual void bonus() = 0;
};

class Admin : virtual public Person {
protected:
    float salary;
public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Admin salary: ";
        cin >> salary;
    }
    void displaydata() override {
        Person::displaydata();
        cout << "Admin Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
protected:
    float balance;
public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Account balance: ";
        cin >> balance;
    }
    void displaydata() override {
        Person::displaydata();
        cout << "Account Balance: " << balance << endl;
    }
    void bonus() override {
        cout << "Account Bonus: " << balance * 0.05 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata(); 
        cout << "Enter Balance for Master: ";
        cin >> balance;
    }
    void displaydata() override {
        Admin::displaydata();
        cout << "Balance (from Account): " << balance << endl;
    }
    void bonus() override {
        cout << "Master Total Bonus: " << (salary * 0.10 + balance * 0.05) << endl;
    }
};

int main() {
    Person* p;
    Master m;
    p = &m;

    cout << "\n--- Enter Master Info ---\n";
    p->getdata();

    cout << "\n--- Display Info ---\n";
    p->displaydata();

    cout << "\n--- Bonus Calculation ---\n";
    p->bonus();

    return 0;
}
