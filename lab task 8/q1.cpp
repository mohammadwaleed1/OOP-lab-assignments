#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void reduce()
    {
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    Fraction();
    Fraction(int num, int dem){
        numerator=num; 
        denominator=dem; 
        reduce();}

    Fraction operator+(Fraction &other){
        return Fraction(numerator * other.denominator + other.numerator * denominator,denominator*other.denominator);
    }
    Fraction operator-(Fraction &other){
        return Fraction(numerator * other.denominator - other.numerator * denominator,denominator*other.denominator);
    }
    Fraction operator*(Fraction &other){
        return Fraction(numerator*other.numerator,denominator*other.denominator);
    }
    Fraction operator/(Fraction &other){
        return Fraction(numerator*other.denominator,denominator*other.numerator);
    }
    bool operator==(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return (numerator == other.numerator && denominator == other.denominator);
    }
    bool operator!=(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return !(*this == other);
    }
    bool operator<(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return numerator * other.denominator > other.numerator * denominator;
    }
    bool operator<=(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return !(*this > other);
    }
    bool operator>=(const Fraction& other) {
    	cout<<"Comparing"<<endl;
        return !(*this < other);
    } 
    friend ostream&operator<<(ostream& out, const Fraction& f);
    friend istream&operator>>(istream& in, Fraction& f);
};
ostream& operator<<(ostream& out, const Fraction& f) {
    if (f.denominator == 1) {
        out << f.numerator; // show just whole number
    } else if (f.numerator == 0) {
        out << 0;
    } else {
        out << f.numerator << "/" << f.denominator;
    }
    return out;
}
istream&operator>>(istream& in, Fraction& f){
    in>>f.numerator>>f.denominator;
    return in;
}
int main (){
    Fraction f1(6,8),f2(1,4);
    cout<<"first fraction:"<<f1<<endl;
    cout<<"second fraction:"<<f2<<endl;
    cout << "Sum: " << (f1 + f2) << endl;
    cout << "Difference: " << (f1 - f2) << endl;
    cout << "Product: " << (f1 * f2) << endl;
    cout << "Quotient: " << (f1 / f2) << endl;

    cout << "f1 == f2? " << (f1 == f2 ? "Yes" : "No") << endl;
    cout << "f1 != f2? " << (f1 != f2 ? "Yes" : "No") << endl;
    cout << "f1 < f2? " << (f1 < f2 ? "Yes" : "No") << endl;
    cout << "f1 > f2? " << (f1 > f2 ? "Yes" : "No") << endl;
    cout << "f1 <= f2? " << (f1 <= f2 ? "Yes" : "No") << endl;
    cout << "f1 >= f2? " << (f1 >= f2 ? "Yes" : "No") << endl;
};


