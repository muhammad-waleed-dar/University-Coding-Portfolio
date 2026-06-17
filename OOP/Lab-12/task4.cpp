#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main() {
    string src, dest;
    cout << "Enter source filename: ";
    cin >> src;
    cout << "Enter destination filename: ";
    cin >> dest;

    ifstream fin(src);
    ofstream fout(dest);

    if (!fin || !fout) {
        cout << "File error!\n";
        return 0;
    }

    // istream_iterator<int> in(fin);   
    // istream_iterator<int> end;     
    // ostream_iterator<int> out(fout, " "); 

    // while (in != end) {
    //     *out = *in;  
    //     ++out;       
    //     ++in;        
    // }

    vector<int> numbers((istream_iterator<int>(fin)), istream_iterator<int>());

    for (int i = numbers.size() - 1; i >= 0; i--)
        fout << numbers[i] << " ";

    cout << "Copy complete in reverse order.\n";

    cout << "Copy complete.\n";
    return 0;
}



    // vector<int> numbers((istream_iterator<int>(fin)), istream_iterator<int>());

    // for (int i = numbers.size() - 1; i >= 0; i--)
    //     fout << numbers[i] << " ";

    // cout << "Copy complete in reverse order.\n";