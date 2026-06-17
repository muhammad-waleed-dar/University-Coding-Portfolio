#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "How many words? ";
    cin >> n;

    vector<string> words;
    string w;

    cout << "Enter words:\n";
    for (int i = 0; i < n; i++) {
        cin >> w;
        words.push_back(w);
    }

    sort(words.begin(), words.end());

    cout << "Sorted words:\n";
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << " ";

    return 0;
}
