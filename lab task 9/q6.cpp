#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    virtual void setModel(string m) { model = m; }
    virtual void setPrice(float p) = 0; 
    virtual string getModel() { return model; }
    virtual float getPrice() { return price; }
};

class Color : public Car {
private:
    string color;
public:
    void setPrice(float p) override {
        price = p + 1000; 
    }
    void setColor(string c) { color = c; }
    void display() {
        cout << "Color Car -> Model: " << model << ", Price: $" << price << ", Color: " << color << endl;
    }
};

class Company : public Car {
private:
    string company;
public:
    void setPrice(float p) override {
        price = p + 2000; 
    }
    void setCompany(string c) { company = c; }
    void display() {
        cout << "Company Car -> Model: " << model << ", Price: $" << price << ", Company: " << company << endl;
    }
};

int main() {
    Color c;
    c.setModel("Sedan");
    c.setPrice(20000);
    c.setColor("Red");
    c.display();

    Company cmp;
    cmp.setModel("SUV");
    cmp.setPrice(30000);
    cmp.setCompany("Toyota");
    cmp.display();

    return 0;
}
