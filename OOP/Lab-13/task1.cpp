#include <iostream>
using namespace std;


class Course {
private:
    string code;
    string title;

public:
    Course() {}
    Course(string c, string t) : code(c), title(t) {}

    void display() const {
        cout << "Course Code: " << code << ", Title: " << title << endl;
    }
};

class Student {
private:
    float cgpa; 

public:
    int roll;
    string name;

    Student() : cgpa(0.0) {}
    Student(int r, string n) : roll(r), name(n), cgpa(0.0) {}

    void setCGPA(float g) {
        if (g >= 0.0 && g <= 4.0)
            cgpa = g;
    }

    float getCGPA() const {
        return cgpa;
    }

    void display() const {
        cout << "Roll: " << roll << ", Name: " << name 
             << ", CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1(101, "Ali");
    s1.setCGPA(3.0);

    Course c1("CS101", "Programming Fundamentals");

    cout << "Student Info:\n";
    s1.display();

    cout << "\nCourse Info:\n";
    c1.display();

    return 0;
}
