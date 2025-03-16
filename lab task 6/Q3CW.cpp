#include <iostream>
using namespace std;
class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    
    void displayInfo() const {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
};
class IOrderTaker {
public:
    void takeOrder() const {
        cout << "Taking an order." << endl;
    }
};
class IOrderPreparer {
public:
    void prepareOrder() const {
        cout << "Preparing an order." << endl;
    }
};
class IBiller {
public:
    void generateBill() const {
        cout << "Generating a bill." << endl;
    }
};
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
};
class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
};
class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
};
class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
};
class Menu {
protected:
    string itemName;
    float price;
public:
    Menu(string item, float cost) : itemName(item), price(cost) {}
    float getPrice() const {
        return price;
    }
};

// Food menu class
class FoodMenu : public Menu {
public:
    FoodMenu(string item, float cost) : Menu(item, cost) {}
    
    float calculateFoodCost() const {
        return getPrice();
    }
};
class BeverageMenu : public Menu {
private:
    float taxRate;
public:
    BeverageMenu(string item, float cost, float tax) : Menu(item, cost), taxRate(tax) {}
    
    float calculateBeverageCost() const {
        return getPrice() + (getPrice() * taxRate);
    }
};

int main() {
    Waiter waiter(101, "John");
    Chef chef(102, "Alice");
    Cashier cashier(103, "Bob");
    Manager manager(104, "Sarah");
    
    waiter.takeOrder();
    chef.prepareOrder();
    cashier.generateBill();
    manager.takeOrder();
    manager.generateBill();
    
    FoodMenu food("Burger", 5.99);
    BeverageMenu beverage("Coke", 1.99, 0.1);
    
    cout << "Total cost of food item: " << food.calculateFoodCost() << endl;
    cout << "Total cost of beverage item: " << beverage.calculateBeverageCost() << endl;
    
    return 0;
}
