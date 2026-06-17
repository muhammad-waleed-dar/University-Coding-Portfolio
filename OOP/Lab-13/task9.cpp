#include <iostream>
#include <vector>
#include <map>
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
    void enrollCourse(const Course& c) { courses.push_back(c); }
    float getCGPA() const { return cgpa; }
    void display() const {
        cout << roll << " | " << name << " | CGPA: " << cgpa << " | Courses: ";
        for (auto &c : courses) cout << c.code << " ";
        cout << endl;
    }
};

int main() {

    Course cs101("CS101", "Programming");
    Course mt101("MT101", "Discrete Math");


    vector<Student> students = {
        Student(101, "Waleed", 3.85),
        Student(102, "Ali", 3.5),
        Student(103, "Ahmed", 3.95)
    };

    students[0].enrollCourse(cs101);
    students[0].enrollCourse(mt101);
    students[1].enrollCourse(cs101);
    students[2].enrollCourse(mt101);


    map<int, Student> studentMap;
    for (auto &s : students)
        studentMap[s.roll] = s;

    cout << "Students by Roll:\n";
    for (auto &p : studentMap) {
        cout << "Roll " << p.first << " -> ";
        p.second.display();
    }

    map<string, int> courseCount;
    for (auto &s : students) {
        for (auto &c : s.courses)
            courseCount[c.code]++;
    }

    cout << "\nStudents per course:\n";
    for (auto &p : courseCount)
        cout << p.first << " : " << p.second << " student(s)\n";

    return 0;
}
