#include <iostream>
#include <string>

using namespace std;

// function to print the binary of n
void base2of(int n)
{
	if(n==0)
    return;

    base2of(n/2);
    cout<< n%2;
}


// a test case of base2of function
// verify it, and add more test cases
int main()
{
	cout << "the binary number for " << endl;
	cout << 5 << " is "; base2of(5); cout << endl;
	cout << 16 << " is "; base2of(16); cout << endl;
	cout << 65 << " is "; base2of(65); cout << endl;
	cout << 1023 << " is "; base2of(1023); cout << endl;
	cout << 798375 << " is "; base2of(798375); cout << endl;
    cout << 255 << " is "; base2of(255); cout << endl;
    cout << 65535 << " is "; base2of(65535); cout << endl;
	cout << endl;

	return 0;
}