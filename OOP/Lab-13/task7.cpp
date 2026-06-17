#include <iostream>
#include <vector>
#include <algorithm>
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
        cout << "Roll: " << roll << ", Name: " << name << ", CGPA: " << cgpa << endl;
        cout << "Courses: ";
        for (auto &c : courses) cout << c.code << " ";
        cout << endl;
    }
};

int main() {
    vector<Student> students = {
        Student(101, "Waleed", 3.85),
        Student(102, "Ali", 3.5),
        Student(103, "Ahmed", 3.95)
    };

    Course cs101("CS101", "Programming");
    Course mt101("MT101", "Discrete Math");

    students[0].enrollCourse(cs101);
    students[0].enrollCourse(mt101);
    students[1].enrollCourse(cs101);

    int searchRoll = 102;
    auto it = find_if(students.begin(), students.end(), [&](Student &s){ return s.roll == searchRoll; });
    if (it != students.end()) {
        cout << "Student found:\n";
        it->display();
    }

    float minCGPA = 3.6;
    int countHighCGPA = count_if(students.begin(), students.end(), [&](Student &s){ return s.getCGPA() >= minCGPA; });
    cout << "\nNumber of students with CGPA >= " << minCGPA << ": " << countHighCGPA << endl;

    cout << "\nAll students:\n";
    for_each(students.begin(), students.end(), [](Student &s){ s.display(); cout << "----------------\n"; });

    return 0;
}
