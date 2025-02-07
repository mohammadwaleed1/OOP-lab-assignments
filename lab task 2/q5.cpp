#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Employee {
    int id;
    string name;
}emp;

int main() {
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    emp employees[n]; 

    for (int i = 0; i < n; ++i) {
        cout << "Enter ID and Name for employee " << i + 1 << ": ";
        cin >> employees[i].id;
        cin.ignore();  // To ignore the newline character after ID
        getline(cin, employees[i].name);
    }

    // Sort the array by ID first, and by name second (default comparison works)
   // sort(employees, employees + n);

    // Print the sorted employee details
    cout << "\nSorted Employee Details:\n";
    for (int i = 0; i < n; ++i) {
        cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << endl;
    }

    return 0;
}
