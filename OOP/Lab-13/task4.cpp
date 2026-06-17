#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    float cgpa;

public:
    int roll;
    string name;

    Student() : cgpa(0.0) {}
    Student(int r, string n, float g = 0.0) : roll(r), name(n), cgpa(g) {}

    void setCGPA(float g) {
        if (g >= 0.0 && g <= 4.0)
            cgpa = g;
    }

    float getCGPA() const { return cgpa; }

    void display() const {
        cout << "Roll: " << roll << ", Name: " << name
             << ", CGPA: " << cgpa << endl;
    }
};

int main() {
    vector<Student> students; 

    students.push_back(Student(101, "Waleed", 3.85));
    students.push_back(Student(102, "Ali", 3.5));
    students.push_back(Student(103, "Ahmed", 3.95));

    cout << "All Students:\n";
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        it->display();
    }

    return 0;
}
