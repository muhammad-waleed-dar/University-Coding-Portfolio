#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    string code;
    string title;

    Course() {}
    Course(string c, string t) : code(c), title(t) {}

    void display() const {
        cout << code << " : " << title << endl;
    }
};

class Student {
private:
    float cgpa;

public:
    int roll;
    string name;
    vector<Course> courses;

    Student() : cgpa(0.0) {}
    Student(int r, string n, float g = 0.0) : roll(r), name(n), cgpa(g) {}

    void setCGPA(float g) { cgpa = g; }
    float getCGPA() const { return cgpa; }

    void enrollCourse(const Course& c) { courses.push_back(c); }

    void display() const {
        cout << "Roll: " << roll << ", Name: " << name
             << ", CGPA: " << cgpa << endl;
        if (!courses.empty()) {
            cout << "Courses:\n";
            for (auto &c : courses)
                cout << "  - " << c.code << " : " << c.title << endl;
        }
    }
};

int main() {
    Course cs101("CS101", "Programming Fundamentals");
    Course mt101("MT101", "Discrete Mathematics");

    Student s1(101, "Waleed", 3.85);
    Student s2(102, "Ali", 3.5);

    s1.enrollCourse(cs101);
    s1.enrollCourse(mt101);
    s2.enrollCourse(cs101);

    vector<Student> students;
    students.push_back(s1);
    students.push_back(s2);

    cout << "All Students:\n";
    for (auto &s : students) {
        s.display();
        cout << "----------------\n";
    }

    return 0;
}
