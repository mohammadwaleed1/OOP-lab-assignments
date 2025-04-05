#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int employeeID;

public:
    void getData(int id) {
        employeeID = id;
    }

    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData(int id, const string& empName, double income) {
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Bonus: $" << bonus() << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData(int id, const string& empName, double income) {
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Bonus: $" << bonus() << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

int main() {
    Admin admin1, admin2;
    Accounts acc1, acc2;

    admin1.getData(101, "Alice", 5000);
    admin2.getData(102, "Bob", 6000);
    
    acc1.getData(201, "Charlie", 4500);
    acc2.getData(202, "David", 5500);

    cout << "\nAdmin 1 Information:" << endl;
    admin1.displayData();

    cout << "\nAdmin 2 Information:" << endl;
    admin2.displayData();

    cout << "\nAccount 1 Information:" << endl;
    acc1.displayData();

    cout << "\nAccount 2 Information:" << endl;
    acc2.displayData();

    return 0;
}
