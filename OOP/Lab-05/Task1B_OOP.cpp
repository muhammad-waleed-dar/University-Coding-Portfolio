#include <iostream>
using namespace std;

class Calculator {
private:
    float a;
    float b;

public:
    Calculator(float x = 0.0f, float y = 0.0f) : a(x), b(y) {
        cout << "Calculator constructed (" << a << ", " << b << ")\n";
    }

    Calculator(const Calculator& other) : a(other.a), b(other.b) {
        cout << "Calculator copied (" << a << ", " << b << ")\n";
    }

    ~Calculator() {
        cout << "Calculator destructed (" << a << ", " << b << ")\n";
    }

    float add() const      { return a + b; }
    float subtract() const { return a - b; }
    float multiply() const { return a * b; }
    float divide() const   { return b != 0 ? a / b : 0; }

    void setValues(float x, float y) { a = x; b = y; }
};

int main() {
    Calculator c(10.0f, 5.0f);

    cout << "Add: "      << c.add() << endl;
    cout << "Subtract: " << c.subtract() << endl;
    cout << "Multiply: " << c.multiply() << endl;
    cout << "Divide: "   << c.divide() << endl;

    Calculator c2 = c; 
    cout << "Copy Add: " << c2.add() << endl;

    return 0;
}
