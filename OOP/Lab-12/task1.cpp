#include <iostream>
#include <algorithm>   
using namespace std;

int main() {
    int n;
    cout << "Enter number of values: ";
    cin >> n;

    float arr[100];  
    cout << "Enter " << n << " floating values:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    cout << "Sorted values:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
