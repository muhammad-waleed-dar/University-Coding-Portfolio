#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter limit: ";
    cin >> n;

    int evenArr[100];
    int eCount = 0;

    set<int> oddSet;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            evenArr[eCount++] = i;
        else
            oddSet.insert(i);
    }

    vector<int> merged;
    merged.resize(eCount + oddSet.size());

    merge(evenArr, evenArr + eCount,
          oddSet.begin(), oddSet.end(),
          merged.begin());

    cout << "Merged vector:\n";
    for (int x : merged)
        cout << x << " ";

    return 0;
}
