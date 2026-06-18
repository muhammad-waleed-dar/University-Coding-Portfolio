#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;

// understand the following code and then
// code the rest of the Polynomial related
// functions

// Type Polynomial is just an array of 10 ints
// its indices consides with the powers of 
// Polynomial's variable, and values are the 
// coefficient
typedef array<int, 10> Polynomial;

void showPolynomial(Polynomial);
Polynomial addPolynomials(Polynomial, Polynomial);
int evaluatePolynomial(Polynomial, int);

int main()
{
    Polynomial p1{-7, 1, -5, 0, 3, 0, 0, 0, 0, 0};
    Polynomial p2{1, 2, 3}; // rest of indices will become 0 by default

    cout << "Polynomial p1 is: ";
    showPolynomial(p1);
    cout << endl;
    cout << "Polynomial p2 is: ";
    showPolynomial(p2);
    cout << endl;

    Polynomial sum = addPolynomials(p1, p2);

    cout << "Sum of p1 and p2 is: ";
    showPolynomial(sum);
    cout << endl;

    int x = 2;
    cout << "p1 evaluated at x = " << x << " is: "
         << evaluatePolynomial(p1, x) << endl;

    cout << "p2 evaluated at x = " << x << " is: "
         << evaluatePolynomial(p2, x) << endl;


	return 0;
}

// this implementation can be improved many folds
void showPolynomial(Polynomial p)
{
    int j = 9;
    while(p[j] == 0 && j >=0) // skip extra leading zeros
    {
        j = j-1;
    }
    while(j >=0)
    {
        cout << ' ';
        if(p[j]>=0)
        {
            cout << '+';
        }
        cout << p[j] << 'x' << '^' << j;
        j = j-1;
    }
    
    return;
}

int evaluatePolynomial(Polynomial p, int x)
{
    int result = 0;

    for (int i = 0; i < 10; i++)
    {
        result += p[i] * pow(x, i);
    }

    return result;
}


Polynomial addPolynomials(Polynomial p1, Polynomial p2)
{
    Polynomial result{};  // initializes all elements to 0

    for (int i = 0; i < 10; i++)
    {
        result[i] = p1[i] + p2[i];
    }

    return result;
}

// Again, for provided file tasks7, read the code in it carefully and convert if needed the type 
// Polynomial to a CPP class. Understand the provided code of the showPolynomial functions and 
// write definitions of the other two declared functions and test them through main function.