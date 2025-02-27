#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
public:
    string Name;
    vector<MenuItem> Menu;
    vector<string> Orders;

    CoffeeShop(string shopName) : Name(shopName) {}

    void addMenuItem(string name, string type, double price) {
        Menu.push_back(MenuItem(name, type, price));
    }

    void addOrder(string itemName) {
        bool found = false;
        for (int i = 0; i < Menu.size(); ++i) {
            if (Menu[i].name == itemName) {
                Orders.push_back(itemName);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "This item is currently unavailable!" << endl;
        }
    }

    void fulfillOrder() {
        if (Orders.size() > 0) {
            cout << "The " << Orders.front() << " is ready!" << endl;
            Orders.erase(Orders.begin());
        } else {
            cout << "All orders have been fulfilled." << endl;
        }
    }

    void listOrders() {
        if (Orders.size() > 0) {
            cout << "Current Orders: ";
            for (int i = 0; i < Orders.size(); ++i) {
                cout << Orders[i] << " ";
            }
            cout << endl;
        } else {
            cout << "No orders taken." << endl;
        }
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < Orders.size(); ++i) {
            for (int j = 0; j < Menu.size(); ++j) {
                if (Menu[j].name == Orders[i]) {
                    total += Menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (Menu.empty()) return "";

        string cheapestName = Menu[0].name;
        double minPrice = Menu[0].price;

        for (int i = 1; i < Menu.size(); ++i) {
            if (Menu[i].price < minPrice) {
                minPrice = Menu[i].price;
                cheapestName = Menu[i].name;
            }
        }

        return cheapestName;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (int i = 0; i < Menu.size(); ++i) {
            if (Menu[i].type == "drink") {
                drinks.push_back(Menu[i].name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foodItems;
        for (int i = 0; i < Menu.size(); ++i) {
            if (Menu[i].type == "food") {
                foodItems.push_back(Menu[i].name);
            }
        }
        return foodItems;
    }
};

int main() {
    CoffeeShop shop("Brewed Awakenings");

    shop.addMenuItem("Espresso", "drink", 2.50);
    shop.addMenuItem("Latte", "drink", 3.00);
    shop.addMenuItem("Cappuccino", "drink", 3.50);
    shop.addMenuItem("Croissant", "food", 2.00);
    shop.addMenuItem("Muffin", "food", 1.50);

    cout << "Welcome to " << shop.Name << "!" << endl;

    shop.addOrder("Espresso");
    shop.addOrder("Muffin");
    shop.addOrder("Latte");
    shop.addOrder("Bagel");

    shop.listOrders();

    shop.fulfillOrder();

    shop.listOrders();

    cout << "Total amount due: $" << shop.dueAmount() << endl;

    cout << "The cheapest item is: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks only: ";
    for (const auto& drink : drinks) {
        cout << drink << " ";
    }
    cout << endl;

    vector<string> food = shop.foodOnly();
    cout << "Food only: ";
    for (const auto& foodItem : food) {
        cout << foodItem << " ";
    }
    cout << endl;

    return 0;
}
