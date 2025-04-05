#include<iostream>
#include<vector>
using namespace std;

class poly {
public:
    int degree;
    vector<int> coeff;  

    poly(int d = 0) : degree(d), coeff(d + 1, 0) {}

    poly(int d, int* values) : degree(d) {
        coeff.resize(d + 1);
        for (int i = 0; i <= d; i++) {
            coeff[i] = values[i];
        }
    }

    
    ~poly() {}

    poly(const poly& other) : degree(other.degree), coeff(other.coeff) {}

    poly(poly&& other) noexcept : degree(other.degree), coeff(move(other.coeff)) {}

    void display() const {
        for (int i = degree; i >= 0; i--) {
            cout << coeff[i];
            if (i > 0) cout << "x^" << i << " + ";
        }
    }

    double evaluate(double x) const {
        double result = 0;
        double power = 1;
        for (int i = 0; i <= degree; i++) {
            result += coeff[i] * power;
            power *= x;  
        }
        return result;
    }

    poly add(const poly& other) const {
        int maxDegree = (degree > other.degree) ? degree : other.degree;
        poly result(maxDegree);

        for (int i = 0; i <= degree; i++) {
            result.coeff[i] += coeff[i];
        }
        for (int i = 0; i <= other.degree; i++) {
            result.coeff[i] += other.coeff[i];
        }

        return result;
    }

    poly multiply(const poly& other) const {
        int newDegree = degree + other.degree;
        poly result(newDegree);
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result.coeff[i + j] += coeff[i] * other.coeff[j];
            }
        }

        return result;
    }
};

int main() {
    int coeffs1[] = {1, 2, 3}; 
    int coeffs2[] = {0, 1, 4};  

    poly p1(2, coeffs1);  
    poly p2(2, coeffs2);  

    cout << "Polynomial 1: ";
    p1.display();
    cout << endl;

    cout << "Polynomial 2: ";
    p2.display();
    cout << endl;

    poly sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();
    cout << endl;

    poly product = p1.multiply(p2);
    cout << "Product: ";
    product.display();
    cout << endl;

    double x = 2.0;
    cout << "Evaluation of Polynomial 1 at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
