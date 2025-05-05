#include <iostream>

using namespace std;

template<typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}

    T multiplyBase() const {
        return a * b;
    }

    void printBaseProduct() const {
        cout << "Base multiplication: " << multiplyBase() << endl;
    }
};

template<typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T m, T n)
        : Base<T>(x, y), c(m), d(n) {}

    T multiplyDerived() const {
        return c * d;
    }

    void printDerivedProduct() const {
        cout << "Derived multiplication: " << multiplyDerived() << endl;
    }

    void printAllProducts() const {
        this->printBaseProduct();
        printDerivedProduct();
    }
};
