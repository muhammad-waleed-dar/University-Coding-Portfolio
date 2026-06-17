#include <iostream>
using namespace std;

class PointerInfo {
private:
    int a;
    float b;
    char c;

public:
    PointerInfo(int x = 0, float y = 0.0f, char z = '\0') : a(x), b(y), c(z) {
        cout << "PointerInfo constructed\n";
    }

    PointerInfo(const PointerInfo& other) : a(other.a), b(other.b), c(other.c) {
        cout << "PointerInfo copied\n";
    }

    ~PointerInfo() {
        cout << "PointerInfo destructed\n";
    }

    void showInfo() const {
        cout << "Data Type | Size of Data | Size of Pointer\n";
        cout << "-----------------------------------------\n";
        cout << "int   | " << sizeof(a)    << " bytes | pointer: " << sizeof(&a)    << " bytes\n";
        cout << "float | " << sizeof(b)    << " bytes | pointer: " << sizeof(&b)    << " bytes\n";
        cout << "char  | " << sizeof(c)    << " bytes | pointer: " << sizeof(&c)    << " bytes\n";
        cout << "void* | - bytes | pointer: "   << sizeof((void*)0) << " bytes (sizeof(void*))\n";
    }
};

int main() {
    PointerInfo p(10, 3.14f, 'X');
    p.showInfo();

    PointerInfo q = p;
    q.showInfo();

    return 0;
}


