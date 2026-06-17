#include <iostream>
using namespace std;

class Student {
private:
    float cgpa;

public:
    int roll;
    string name;

    Student() : cgpa(0.0) {}

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
    const int MAX_STUDENTS = 3;
    Student students[MAX_STUDENTS]; 
    int count = 0;

    if (count < MAX_STUDENTS) {
        students[count].roll = 101;
        students[count].name = "Abdullah";
        students[count].setCGPA(3.85);
        count++;
    }

    if (count < MAX_STUDENTS) {
        students[count].roll = 102;
        students[count].name = "Ali";
        students[count].setCGPA(3.5);
        count++;
    }

    if (count < MAX_STUDENTS) {
        students[count].roll = 103;
        students[count].name = "Ahmed";
        students[count].setCGPA(3.95);
        count++;
    }

    if (count >= MAX_STUDENTS) {
        cout << "Cannot add more students! Array full.\n";
    }
    cout << "\nAll Students:\n";
    for (int i = 0; i < count; i++) {
        students[i].display();
    }

    return 0;
}
