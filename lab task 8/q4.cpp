#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    Number operator--() {
        value *= 4;
        return *this;  
    }

    Number operator--(int) {
        Number temp = *this; 
        value /= 4;
        return temp; 
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(16);

    num.print();

    --num;
    num.print();  

    num--;
    num.print();  
    return 0;
}
