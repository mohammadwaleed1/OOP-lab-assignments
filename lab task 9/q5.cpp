#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0; 
};

class Rectangle : public Shape {
private:
    float width, height;
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    float getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle r(10, 5);
    Triangle t(8, 6);

    cout << "Rectangle Area: " << r.getArea() << endl;
    cout << "Triangle Area: " << t.getArea() << endl;

    return 0;
}
