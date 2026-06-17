#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
protected:
    double real, imag;

public:
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {
        cout << "ComplexNumber parameterized/default constructor called\n";
    }

    ComplexNumber(const ComplexNumber& other) {
        real = other.real;
        imag = other.imag;
        cout << "ComplexNumber copy constructor called\n";
    }

    ComplexNumber& operator=(const ComplexNumber& other) {
        cout << "ComplexNumber assignment operator called\n";
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
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }

    ~ComplexNumber() {
        cout << "ComplexNumber destructor called\n";
    }
};

class PolarComplex : public ComplexNumber {
public:
    PolarComplex() : ComplexNumber() {
        cout << "PolarComplex default constructor called\n";
    }

    PolarComplex(double r, double i) : ComplexNumber(r, i) {
        cout << "PolarComplex parameterized constructor called\n";
    }

    PolarComplex(const PolarComplex& other) : ComplexNumber(other) {
        cout << "PolarComplex copy constructor called\n";
    }

    PolarComplex& operator=(const PolarComplex& other) {
        cout << "PolarComplex assignment operator called\n";
        if (this != &other) {
            ComplexNumber::operator=(other); 
        }
        return *this;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double phase() const {
        return atan2(imag, real) * (180.0 / M_PI);
    }

    void toPolar() const {
        cout << "[" << magnitude() << "] ∠ [" << phase() << "°]" << endl;
    }

    PolarComplex operator!() const {
        return PolarComplex(real, -imag);
    }
};

int main() {
    cout << "\n=== Testing PolarComplex ===\n";

    PolarComplex p1(3, 4);
    PolarComplex p2(1, -2);

    cout << "\nRectangular form:\n";
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    cout << "\nPolar form:\n";
    p1.toPolar();
    p2.toPolar();

    cout << "\nConjugate of p1: " << !p1 << endl;
    cout << "Conjugate in polar form: ";
    (!p1).toPolar();

    cout << "\nTesting copy constructor:\n";
    PolarComplex p3 = p1;

    cout << "\nTesting assignment operator:\n";
    p2 = p1;
}
