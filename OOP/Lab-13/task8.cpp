#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    float cgpa;

public:
    int roll;
    string name;
    int semester;

    Student(int r, string n, float g, int sem) : roll(r), name(n), cgpa(g), semester(sem) {}
    float getCGPA() const { return cgpa; }
    void display() const { cout << roll << " | " << name << " | CGPA: " << cgpa << " | Sem: " << semester << endl; }
};

int main() {
    vector<Student> students = {
        Student(103, "Ahmed", 3.95, 4),
        Student(101, "Waleed", 3.85, 3),
        Student(102, "Ali", 3.5, 2)
    };

    sort(students.begin(), students.end(), [](Student &a, Student &b){ return a.roll < b.roll; });
    cout << "Sorted by Roll:\n";
    for (auto &s : students) s.display();

    sort(students.begin(), students.end(), [](Student &a, Student &b){ return a.getCGPA() > b.getCGPA(); });
    cout << "\nSorted by CGPA Desc:\n";
    for (auto &s : students) s.display();

    sort(students.begin(), students.end(), [](Student &a, Student &b){ return a.semester < b.semester; });
    cout << "\nSorted by Semester:\n";
    for (auto &s : students) s.display();

    return 0;
}
