#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Student {
public:
    int roll;
    string name;
    Student(int r, string n) : roll(r), name(n) {}
};

class Course {
public:
    string code;
    string title;

    Course(string c, string t) : code(c), title(t) {}

    bool operator<(const Course &other) const {
        return code < other.code;
    }
};

int main() {

    Course cs101("CS101", "Programming");
    Course mt101("MT101", "Discrete Math");


    Student s1(101, "Waleed");
    Student s2(102, "Ali");
    Student s3(103, "Ahmed");

    map<Course, vector<Student>> courseMap;

    courseMap[cs101].push_back(s1);
    courseMap[cs101].push_back(s2);
    courseMap[mt101].push_back(s1);
    courseMap[mt101].push_back(s3);

    for (auto &p : courseMap) {
        cout << p.first.code << " - " << p.first.title << ":\n";
        for (auto &s : p.second)
            cout << "  " << s.roll << " | " << s.name << endl;
    }

    return 0;
}
