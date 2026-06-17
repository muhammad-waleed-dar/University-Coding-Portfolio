#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    float GPA;
    string CNIC;

public:
    string name;
    int semester;
    string departmentName;
    static int studentCount;

    Student() : name("Unknown"), rollNo(0), GPA(0.0), semester(0), departmentName("None") {
        studentCount++;
    }

    Student(string n, int r, float g, int sem, string dept)
        : name(n), semester(sem), departmentName(dept) {
        rollNo = r > 0 ? r : 1;
        GPA = (g >= 0.0 && g <= 4.0) ? g : 0.0;
        studentCount++;
    }

    Student(const Student& s) {
        name = s.name;
        rollNo = s.rollNo;
        GPA = s.GPA;
        semester = s.semester;
        departmentName = s.departmentName;
        CNIC = s.CNIC;
        studentCount++;
        cout << "Copy Constructor called for Student: " << name << endl;
    }

    ~Student() { studentCount--; }

    void display() {
        cout << "Student: " << name << " | RollNo: " << rollNo
             << " | GPA: " << GPA << " | Semester: " << semester
             << " | Dept: " << departmentName << endl;
    }

    static int getCount() { return studentCount; }
};
int Student::studentCount = 0;


class Faculty {
private:
    float salary;
    string CNIC;

public:
    string name, designation, departmentName;
    static int facultyCount;

    Faculty() : name("Unknown"), designation("None"), departmentName("None"), salary(0.0) {
        facultyCount++;
    }

    Faculty(string n, string d, string dept, float s) : name(n), designation(d), departmentName(dept), salary(s) {
        facultyCount++;
    }

    Faculty(const Faculty& f) {
        name = f.name;
        designation = f.designation;
        departmentName = f.departmentName;
        salary = f.salary;
        CNIC = f.CNIC;
        facultyCount++;
        cout << "Copy Constructor called for Faculty: " << name << endl;
    }

    ~Faculty() { facultyCount--; }

    void display() {
        cout << "Faculty: " << name << " | " << designation << " | Dept: " << departmentName
             << " | Salary: " << salary << endl;
    }

    static int getCount() { return facultyCount; }
};
int Faculty::facultyCount = 0;


class Course {
private:
    string courseCode;
    int creditHours;

public:
    string courseName, instructorName;
    static int courseCount;

    Course() : courseName("None"), courseCode("000"), creditHours(0), instructorName("Unknown") {
        courseCount++;
    }

    Course(string cname, string code, int ch, string inst)
        : courseName(cname), courseCode(code), creditHours(ch), instructorName(inst) {
        courseCount++;
    }

    Course(const Course& c) {
        courseName = c.courseName;
        courseCode = c.courseCode;
        creditHours = c.creditHours;
        instructorName = c.instructorName;
        courseCount++;
        cout << "Copy Constructor called for Course: " << courseName << endl;
    }

    ~Course() { courseCount--; }

    void display() {
        cout << "Course: " << courseName << " (" << courseCode << ") | Credits: " << creditHours
             << " | Instructor: " << instructorName << endl;
    }

    static int getCount() { return courseCount; }
};
int Course::courseCount = 0;


class Department {
private:
    Student s1;
    Faculty f1;
    Course c1;

public:
    string departmentName, hodName;
    static int departmentCount;

    Department() : departmentName("None"), hodName("None") { departmentCount++; }

    Department(string d, string h, Student s, Faculty f, Course c)
        : departmentName(d), hodName(h), s1(s), f1(f), c1(c) {
        departmentCount++;
    }

    Department(const Department& d)
        : departmentName(d.departmentName), hodName(d.hodName), s1(d.s1), f1(d.f1), c1(d.c1) {
        departmentCount++;
        cout << "Copy Constructor called for Department: " << departmentName << endl;
    }

    ~Department() { departmentCount--; }

    void display() {
        cout << "\nDepartment: " << departmentName << " | HOD: " << hodName << endl;
        s1.display();
        f1.display();
        c1.display();
    }

    static int getCount() { return departmentCount; }
};
int Department::departmentCount = 0;


class Library {
private:
    string libName;

public:
    static int libraryCount;

    Library() : libName("Unknown") { libraryCount++; }
    Library(string l) : libName(l) { libraryCount++; }

    Library(const Library& l) { libName = l.libName; libraryCount++; }

    ~Library() { libraryCount--; }

    void setName(string l) { libName = l; }
    string getName() { return libName; }

    void display() { cout << "Library: " << libName << endl; }

    static int getCount() { return libraryCount; }
};
int Library::libraryCount = 0;


class Hostel {
private:
    string hostelName;
    int capacity;

public:
    static int hostelCount;

    Hostel() : hostelName("None"), capacity(0) { hostelCount++; }
    Hostel(string h, int c) : hostelName(h), capacity(c) { hostelCount++; }

    Hostel(const Hostel& h) { hostelName = h.hostelName; capacity = h.capacity; hostelCount++; }

    ~Hostel() { hostelCount--; }

    void setName(string h) { hostelName = h; }
    void setCapacity(int c) { capacity = c; }

    void display() { cout << "Hostel: " << hostelName << " | Capacity: " << capacity << endl; }

    static int getCount() { return hostelCount; }
};
int Hostel::hostelCount = 0;


class Campus {
private:
    string campusName;
    string location;

public:
    static int campusCount;

    Campus() : campusName("Unknown"), location("Unknown") { campusCount++; }
    Campus(string c, string l) : campusName(c), location(l) { campusCount++; }

    Campus(const Campus& c) { campusName = c.campusName; location = c.location; campusCount++; }

    ~Campus() { campusCount--; }

    void setCampus(string c, string l) { campusName = c; location = l; }
    void display() { cout << "Campus: " << campusName << " | Location: " << location << endl; }

    static int getCount() { return campusCount; }
};
int Campus::campusCount = 0;


class University {
private:
    string uniName;

public:
    static int uniCount;

    University() : uniName("Unknown") { uniCount++; }
    University(string u) : uniName(u) { uniCount++; }

    University(const University& u) { uniName = u.uniName; uniCount++; }

    ~University() { uniCount--; }

    void setName(string u) { uniName = u; }
    void display() { cout << "\nUniversity: " << uniName << endl; }

    static int getCount() { return uniCount; }
};
int University::uniCount = 0;

class ViceChancellor {
private:
    static ViceChancellor* instance;
    static int vcCount;
    string name;
    int age;

    ViceChancellor(string n, int a) : name(n), age(a) {
        cout << "Vice Chancellor constructor called for " << name << endl;
        vcCount++;
    }

public:
    ViceChancellor(const ViceChancellor&) = delete;
    void operator=(const ViceChancellor&) = delete;

    static ViceChancellor* getInstance(string n = "Default VC", int a = 60) {
        if (instance == nullptr) {
            instance = new ViceChancellor(n, a);
        } else {
            cout << "VC already exists, returning existing instance\n";
        }
        return instance;
    }

    void display() { cout << "Vice Chancellor: " << name << ", Age: " << age << endl; }

    static int getCount() { return vcCount; }

    ~ViceChancellor() { vcCount--; }
};
ViceChancellor* ViceChancellor::instance = nullptr;
int ViceChancellor::vcCount = 0;


int main() {
    cout << "--- Campus Management System ---\n";

    Student s1("Ali", 101, 3.5, 2, "CS");
    Student s2 = s1;   
    s2.name = "Copied Ali";

    Faculty f1("Prof. A", "Lecturer", "CS", 50000);
    Faculty f2 = f1;   

    Course c1("OOP", "CS201", 3, "Prof. A");
    Course c2 = c1;    

    Department d1("Computer Science", "Dr. Ali", s1, f1, c1);
    Department d2 = d1; 

    Library lib("Central Library");
    Hostel h("Hostel A", 200);
    Campus camp("Main Campus", "Lahore");
    University uni("PUCIT");

    ViceChancellor* vc = ViceChancellor::getInstance("Dr. Khan", 55);

    uni.display();
    d1.display();
    lib.display();
    h.display();
    camp.display();
    vc->display();

    cout << "\n--- Static Counts ---\n";
    cout << "Students: " << Student::getCount() << endl;
    cout << "Faculty: " << Faculty::getCount() << endl;
    cout << "Courses: " << Course::getCount() << endl;
    cout << "Departments: " << Department::getCount() << endl;
    cout << "Libraries: " << Library::getCount() << endl;
    cout << "Hostels: " << Hostel::getCount() << endl;
    cout << "Campuses: " << Campus::getCount() << endl;
    cout << "Universities: " << University::getCount() << endl;
    cout << "Vice Chancellors: " << ViceChancellor::getCount() << endl;

    return 0;
}
