#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber() : real(0), imag(0) {
        cout << "Default constructor called\n";
    }

    ComplexNumber(double r, double i) : real(r), imag(i) {
        cout << "Parameterized constructor called\n";
    }

    ComplexNumber(const ComplexNumber& other) {
        real = other.real;
        imag = other.imag;
        cout << "Copy constructor called\n";
    }

    ComplexNumber& operator=(const ComplexNumber& other) {
        cout << "Assignment operator called\n";
        if (this != &other) { 
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        double r = (real * other.real) - (imag * other.imag);
        double i = (real * other.imag) + (imag * other.real);
        return ComplexNumber(r, i);
    }

    bool operator==(const ComplexNumber& other) const {
        return (real == other.real && imag == other.imag);
    }

    friend ostream& operator<<(ostream& out, const ComplexNumber& c) {
        if (c.imag >= 0)
            out << c.real << " + " << c.imag << "i";
        else
            out << c.real << " - " << -c.imag << "i";
        return out;
    }

    ~ComplexNumber() {
    cout << "Destructor called\n";
}
};


int main() {
    cout << "Creating c1 using default constructor.\n";
    ComplexNumber c1;

    cout << "\nCreating c2 using parameterized constructor.\n";
    ComplexNumber c2(3.5, 2.5);

    cout << "\nCreating c3 using copy constructor from c2.\n";
    ComplexNumber c3 = c2;

    cout << "\nAssigning c1 = c2.\n";
    c1 = c2; 

    cout << "\nTesting arithmetic operators.\n";
    ComplexNumber c4 = c2 + c3;
    ComplexNumber c5 = c2 - c3;
    ComplexNumber c6 = c2 * c3;

    cout << "\nc2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 (c2 + c3) = " << c4 << endl;
    cout << "c5 (c2 - c3) = " << c5 << endl;
    cout << "c6 (c2 * c3) = " << c6 << endl;

    cout << "\nChecking equality.\n";
    if (c2 == c3)
        cout << "c2 and c3 are equal.\n\n";
    else
        cout << "c2 and c3 are not equal.\n\n";

    return 0;
}
