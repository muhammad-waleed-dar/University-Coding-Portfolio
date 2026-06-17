#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    string code;
    string title;
    Course(string c, string t) : code(c), title(t) {}
};

class Student {
private:
    float cgpa;

public:
    int roll;
    string name;
    vector<Course> courses;

    Student(int r, string n, float g) : roll(r), name(n), cgpa(g) {}

    void enrollCourse(const Course& c) {
        courses.push_back(c);
    }

    float getCGPA() const { return cgpa; }
    void display() const {
        cout << "Roll: " << roll << ", Name: " << name << ", CGPA: " << cgpa << endl;
        cout << "Courses: ";
        for (auto &c : courses) cout << c.code << " ";
        cout << endl;
    }
};

int main() {

    Course cs101("CS101", "Programming");
    Course mt101("MT101", "Discrete Math");

    vector<Student> students;
    students.push_back(Student(101, "Waleed", 3.85));
    students.push_back(Student(102, "Ali", 3.5));
    students.push_back(Student(103, "Ahmed", 3.95));

    students[0].enrollCourse(cs101);
    students[0].enrollCourse(mt101);
    students[1].enrollCourse(cs101);

    int searchRoll = 102;
    for (auto &s : students) {
        if (s.roll == searchRoll) {
            cout << "Student found:\n";
            s.display();
        }
    }

    float minCGPA = 3.6;
    cout << "\nStudents with CGPA >= " << minCGPA << ":\n";
    for (auto &s : students) {
        if (s.getCGPA() >= minCGPA)
            s.display();
    }

    for (auto &s : students) {
        cout << s.name << " has " << s.courses.size() << " course(s)." << endl;
    }

    return 0;
}
