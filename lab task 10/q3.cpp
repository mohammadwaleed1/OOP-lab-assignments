#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX = 100; 

int main() {
    ofstream users("users.txt");
    users << "u1 Linus Torvalds Finland linus@example.com\n";
    users << "u2 Alan Turing UK alan@example.com\n";
    users.close();

    ofstream products("products.txt");
    products << "p1 Keyboard Mechanical 100\n";
    products << "p2 Mouse Wireless 50\n";
    products << "p3 Monitor LED 200\n";
    products.close();

    ofstream orders("orders.txt");
    orders << "o1 u1 p1 100\n"; 
    orders << "o2 u1 p3 200\n"; 
    orders << "o3 u2 p2 50\n";  
    orders.close();

    ifstream usersIn("users.txt");
    string line, linus_id = "";
    while (getline(usersIn, line)) {
        istringstream ss(line);
        string id, fname, lname, addr, email;
        ss >> id >> fname >> lname >> addr >> email;
        if (fname == "Linus") {
            linus_id = id;
            break;
        }
    }
    usersIn.close();

    if (linus_id == "") {
        cout << "User Linus not found!" << endl;
        return 1;
    }

    ifstream ordersIn("orders.txt");
    string linus_products[MAX];
    int count = 0;
    while (getline(ordersIn, line)) {
        istringstream ss(line);
        string order_id, user_id, product_id;
        int paid;
        ss >> order_id >> user_id >> product_id >> paid;
        if (user_id == linus_id && count < MAX) {
            linus_products[count++] = product_id;
        }
    }
    ordersIn.close();

    ifstream productsIn("products.txt");
    cout << "\nProducts ordered by Linus:\n";
    while (getline(productsIn, line)) {
        istringstream ss(line);
        string pid, pname, desc;
        int price;
        ss >> pid >> pname >> desc >> price;

        for (int i = 0; i < count; ++i) {
            if (linus_products[i] == pid) {
                cout << pname << endl;
            }
        }
    }
    productsIn.close();

    return 0;
}
