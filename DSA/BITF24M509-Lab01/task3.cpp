#include <iostream>
#include <string>

using namespace std;

// function to compute and return the 
// nth entry of Lucas Numbers, which
// follow the same recurrence relation
// as Fibonacci L_{n}=L_{n-1}+L_{n-2}
// but start with L_{0}=2,L_{1}=1.
// The sequence goes: 2, 1, 3, 4, 7, 11, 18, 29, ....
int nthLucasNumberRecursive(int n)
{
    if(n==0)
    return 2;

    if(n==1)
    return 1;

    return nthLucasNumberRecursive(n-1) + nthLucasNumberRecursive(n-2);
}


// a test case of nthLucasNumberRecursive
//  function, verify it, and add more
int main()
{
	cout << "the 5th Lucas number is ";
	cout << nthLucasNumberRecursive(5);
    cout << endl;
    cout << "the 6th Lucas number is ";
	cout << nthLucasNumberRecursive(6);
	cout << endl;
    cout << "the 7th Lucas number is ";
	cout << nthLucasNumberRecursive(7);
    cout << endl;
    cout << "the 0th Lucas number is ";
	cout << nthLucasNumberRecursive(0);
    cout << endl;
    cout << "the 1st Lucas number is ";
	cout << nthLucasNumberRecursive(1);
    cout << endl;

	return 0;
}