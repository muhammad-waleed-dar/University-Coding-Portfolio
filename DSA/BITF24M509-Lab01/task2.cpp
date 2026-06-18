#include <iostream>
#include <string>

using namespace std;

// function to compute and return the 
// sum of 1st n values of array a
// means return a[0]+a[1]+a[2]+...+a[n-1]
int sumArrayRecursive(int n, int a[])
{
	// write recursive code
	if(n==0)
    return 0;

    return a[n-1] + sumArrayRecursive(n-1, a);

	// your code here
	// you can completely overwrite the 
	// body of this function
}


// a test case of sumArrayRecursive function
// verify it, and add more test cases
int main()
{
	int array[7] = {2, 7, 4, 4, 6, 9, 1};
    int arr[5]={2,3,4,5,6};
    int arr1[3]={2,3,6};
    int arr2[6]={2,3,6,0,-1,-3};
	cout << "the sum of values in array is ";
	cout << sumArrayRecursive(7, array)<<endl;
    cout << "the sum of values in array arr is ";
    cout << sumArrayRecursive(5, arr)<<endl;
    cout << "the sum of values in array arr1 is ";
    cout << sumArrayRecursive(3, arr1)<<endl;
    cout << "the sum of values in array arr2 is ";
    cout << sumArrayRecursive(6, arr2)<<endl;

	cout << endl;

	return 0;
}