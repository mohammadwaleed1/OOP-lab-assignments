#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    Shape(double a) : area(a) {}

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    void displayArea() const {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(20.5), shape2(15.3);
    Shape shape3 = shape1 + shape2;
    shape3.displayArea();
    return 0;
}
