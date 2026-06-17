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
    int size = 2;   
    int count = 0; 
    Student* students = new Student[size];

    // Function to add student dynamically
    auto addStudent = [&](int r, string n, float g) {
        if (count == size) {
            // Resize array: double the size
            int newSize = size * 2;
            Student* temp = new Student[newSize];

            // Copy existing students
            for (int i = 0; i < count; i++)
                temp[i] = students[i];

            // Delete old array and update pointer
            delete[] students;
            students = temp;
            size = newSize;
            cout << "Array resized to " << size << endl;
        }

        // Add new student
        students[count].roll = r;
        students[count].name = n;
        students[count].setCGPA(g);
        count++;
    };

    addStudent(101, "Waleed", 3.85);
    addStudent(102, "Ali", 3.5);
    addStudent(103, "Ahmed", 3.95); 

    cout << "\nAll Students:\n";
    for (int i = 0; i < count; i++) {
        students[i].display();
    }

    delete[] students;

    return 0;
}
