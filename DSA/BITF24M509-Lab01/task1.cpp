#include <iostream>
#include <string>

using namespace std;

// function to compute and return the 
// sum of 1st n values of array a
// means return a[0]+a[1]+a[2]+...+a[n-1]
int sumArrayIterative(int n, int a[])
{
	int ans = 0;
	
	int j=0;
	while(j < n)
	{
		ans += a[j];
		j += 1;
	}
	return ans;
}


// a test case of sumArrayIterative function
// verify it, and add more test cases
int main()
{
	int array[7] = {2, 7, 4, 4, 6, 9, 1};
    int arr[5]={2,3,4,5,6};
    int arr1[3]={2,3,6};
    int arr2[6]={2,3,6,0,-1,-3};
	cout << "the sum of values in array is ";
	cout << sumArrayIterative(7, array)<<endl;
    cout << "the sum of values in array arr is ";
    cout << sumArrayIterative(5, arr)<<endl;
    cout << "the sum of values in array arr1 is ";
    cout << sumArrayIterative(3, arr1)<<endl;
    cout << "the sum of values in array arr2 is ";
    cout << sumArrayIterative(6, arr2)<<endl;

	cout << endl;
	return 0;
}