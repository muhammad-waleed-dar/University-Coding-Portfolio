#include <iostream>
#include <vector>
#include <string>
using namespace std;

int hashFunction(string word, int tableSize)
{
    long long hash = 0;

    for (int i = 0; i < word.length(); i++)
    {
        hash = hash * 31 + word[i];
    }

    return ((hash % tableSize) + tableSize) % tableSize;
}

int main()
{
    vector<string> names =
    {
        "AbdulRehman", "Abdullah", "Ahmad", "Aleeza", "Ali",
        "Amina", "Amna", "Athar", "Ayza", "Bilal",
        "Dania", "Faizan", "Farwa", "Fatima", "Fizza",
        "Furqan", "Haika", "Hassan", "Hira", "Hussnain",
        "Irha", "Kainnat", "Laiba", "Maham", "Mahrukh",
        "Maliaka", "Maryam", "Muattar", "Nabila", "Naveed",
        "Nida", "Rabia", "Rafay", "Sadia", "Shakir",
        "Suleman", "Waleed", "Yahya"
    };

    int tableSize = 171;

    vector<bool> used(tableSize, false);

    cout << "Word\t\tHash" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < names.size(); i++)
    {
        int h = hashFunction(names[i], tableSize);

        cout << names[i] << "\t\t" << h;

        if (used[h])
        {
            cout << "  <-- Collision";
        }
        else
        {
            used[h] = true;
        }

        cout << endl;
    }

    return 0;
}