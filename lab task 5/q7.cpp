#include <iostream>
using namespace std;

class Student {
public:
    const int roll_no; 

    Student(int roll) : roll_no(roll) {} 

    void display() {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter student's roll number: ";
    cin >> roll;

    Student student(roll);  
    student.display();  

    return 0;
}
