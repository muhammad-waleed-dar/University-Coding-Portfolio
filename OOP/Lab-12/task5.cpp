#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

string cleanWord(string w) 
{
    while (!w.empty() && ispunct(w.back()))
        w.pop_back();

    for (int i = 0; i < w.size(); i++)
        w[i] = tolower(w[i]);

    return w;
}

int main() 
{
    string fname;
    cout << "Enter filename: ";
    cin >> fname;

    ifstream fin(fname);
    if (!fin) {
        cout << "File not found!\n";
        return 0;
    }

    map<string, int> freq;
    string word;

    while (fin >> word) {
        word = cleanWord(word);
        if (!word.empty())
            freq[word]++;
    }

    cout << "Frequency Table:\n";
    for (auto &p : freq)
        cout << p.first << " : " << p.second << "\n";

    return 0;
}
