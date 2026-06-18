#include <iostream>
#include <string>

using namespace std;

// function to return the length of 
// c-string (a \0 terminated char array)
int cStrLen(const char s[])
{
    if (s[0] == '\0')
        return 0;

    return 1 + cStrLen(s + 1);

	// your code here
	// you can completely overwrite the 
	// body of this function

}



// a test case of cStrLen function
// verify it, and add more test cases
int main()
{
	cout << "the length for c-string" << endl;
	cout << "Alpha" << " is " << cStrLen("Alpha") << endl;
	cout << "A quick brown fox jumps over the lazy dog" << " is " << cStrLen("A quick brown fox jumps over the lazy dog") << endl;
    cout << "Waleed" << " is " << cStrLen("Waleed") << endl;
    cout << "Muhammad Waleed Dar" << " is " << cStrLen("Muhammad Waleed Dar") << endl;
	return 0;
}