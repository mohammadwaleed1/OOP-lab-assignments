#include <iostream>
#include <cmath> 
using namespace std;
class Circle {
public:
	double radius;
    Circle(double r){
    	radius=r;
	}
    double getArea(){
        return M_PI * radius * radius;
    }
    double getPerimeter(){
        return 2 * M_PI * radius;
    }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
	Circle c(r);
	cout << "Area: " << c.getArea()<<endl;
    cout << "Perimeter: " << c.getPerimeter()<<endl;

    return 0;}