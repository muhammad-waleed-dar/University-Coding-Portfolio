#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
    int rollNo;
    float GPA;
    string CNIC;

public:
    string name;
    int semester;
    string departmentName;

    Student() : name("Unknown"), rollNo(0), GPA(0.0), semester(0), departmentName("None")
    {
        cout << "Default constructor called for Student\n";
    }

    Student(string n, int r, float g, int sem, string dept)
        : name(n), semester(sem), departmentName(dept)
    {
        cout << "Parameterized constructor called for Student: " << name << "\n";
        setRollNo(r);
        setGPA(g);
    }

    ~Student()
    {
        cout << "Destructor called for Student: " << name << "\n";
    }

    void setRollNo(int r)
    {
        if (r <= 0)
        {
            cout << "Invalid Roll No! Setting default.\n";
            rollNo = 1;
        }
        else
        {
            rollNo = r;
        }
    }

    int getRollNo() const { return rollNo; }

    void setGPA(float g)
    {
        if (g < 0.0 || g > 4.0)
        {
            cout << "Invalid GPA! Setting default.\n";
            GPA = 0.0;
        }
        else
        {
            GPA = g;
        }
    }

    float getGPA() const { return GPA; }

    void setCNIC(const string &c) { CNIC = c; }
    string getCNIC() const { return CNIC; }

    void displayStudentInfo() const
    {
        cout << "Student: " << name << " | RollNo: " << rollNo
             << " | GPA: " << GPA << " | Semester: " << semester
             << " | Dept: " << departmentName << endl;
    }
};

class Faculty
{
private:
    float salary;
    string CNIC;

public:
    string name, designation, departmentName;

    Faculty() : name("Unknown"), designation("None"), departmentName("None"), salary(0.0)
    {
        cout << "Default constructor called for Faculty\n";
    }

    Faculty(string n, string des, string dept, float s)
        : name(n), designation(des), departmentName(dept), salary(s)
    {
        cout << "Parameterized constructor called for Faculty: " << name << "\n";
    }

    ~Faculty()
    {
        cout << "Destructor called for Faculty: " << name << "\n";
    }

    void setSalary(float s) { salary = s; }
    float getSalary() const { return salary; }

    void displayFacultyInfo() const
    {
        cout << "Faculty: " << name << " | " << designation
             << " | Dept: " << departmentName << " | Salary: " << salary << endl;
    }
};

class Course
{
private:
    string courseCode;
    int creditHours;

public:
    string courseName, instructorName;

    Course() : courseName("None"), courseCode("000"), creditHours(0), instructorName("Unknown")
    {
        cout << "Default constructor called for Course\n";
    }

    Course(string cname, string code, int ch, string inst)
        : courseName(cname), courseCode(code), creditHours(ch), instructorName(inst)
    {
        cout << "Parameterized constructor called for Course: " << courseName << "\n";
    }

    ~Course()
    {
        cout << "Destructor called for Course: " << courseName << "\n";
    }

    void displayCourseInfo() const
    {
        cout << "Course: " << courseName << " (" << courseCode
             << ") | Credits: " << creditHours << " | Instructor: " << instructorName << endl;
    }
};

class Department
{
private:
    vector<Student> students;
    vector<Faculty> faculty;
    vector<Course> courses;

public:
    string departmentName, hodName;

    Department() : departmentName("None"), hodName("None")
    {
        cout << "Default constructor called for Department\n";
    }

    Department(string dname, string hod) : departmentName(dname), hodName(hod)
    {
        cout << "Parameterized constructor called for Department: " << departmentName << "\n";
    }

    ~Department()
    {
        cout << "Destructor called for Department: " << departmentName << "\n";
    }

    void addStudent(const Student &s) { students.push_back(s); }
    void addFaculty(const Faculty &f) { faculty.push_back(f); }
    void addCourse(const Course &c) { courses.push_back(c); }

    void displayDepartmentInfo() const
    {
        cout << "\nDepartment: " << departmentName << " | HOD: " << hodName << endl;
        cout << "-- Students --\n";
        for (const auto &s : students)
            s.displayStudentInfo();
        cout << "-- Faculty --\n";
        for (const auto &f : faculty)
            f.displayFacultyInfo();
        cout << "-- Courses --\n";
        for (const auto &c : courses)
            c.displayCourseInfo();
    }
};

class Library
{
private:
    vector<string> issuedBooks;

public:
    string libraryName;

    Library() : libraryName("Unknown") { cout << "Default constructor called for Library\n"; }
    Library(string lname) : libraryName(lname) { cout << "Parameterized constructor called for Library: " << libraryName << "\n"; }

    ~Library() { cout << "Destructor called for Library: " << libraryName << "\n"; }

    void issueBook(const Student &s)
    {
        if (issuedBooks.size() < 3)
        {
            issuedBooks.push_back(s.name);
            cout << "Book issued to " << s.name << endl;
        }
        else
        {
            cout << "Library full!\n";
        }
    }

    void displayLibraryInfo() const
    {
        cout << "\nLibrary: " << libraryName << endl;
        for (const auto &name : issuedBooks)
            cout << "Issued to: " << name << endl;
    }
};

class Hostel
{
private:
    vector<Student> stayingStudents;

public:
    string hostelName;
    int capacity;

    Hostel() : hostelName("None"), capacity(0) { cout << "Default constructor called for Hostel\n"; }
    Hostel(string hname, int cap) : hostelName(hname), capacity(cap) { cout << "Parameterized constructor called for Hostel: " << hostelName << "\n"; }

    ~Hostel() { cout << "Destructor called for Hostel: " << hostelName << "\n"; }

    void assignRoom(const Student &s)
    {
        if (stayingStudents.size() < capacity)
        {
            stayingStudents.push_back(s);
            cout << s.name << " assigned in " << hostelName << endl;
        }
        else
        {
            cout << "Hostel full!\n";
        }
    }

    void displayHostelInfo() const
    {
        cout << "\nHostel: " << hostelName << " | Capacity: " << capacity << endl;
        for (const auto &s : stayingStudents)
            cout << "Staying: " << s.name << endl;
    }
};

class Campus
{
private:
    vector<Department> departments;
    Library library;
    Hostel hostel;

public:
    string campusName, location;

    Campus() : campusName("Unknown"), location("Unknown") { cout << "Default constructor called for Campus\n"; }

    Campus(string cname, string loc, Library l, Hostel h)
        : campusName(cname), location(loc), library(l), hostel(h) { cout << "Parameterized constructor called for Campus: " << campusName << "\n"; }

    ~Campus() { cout << "Destructor called for Campus: " << campusName << "\n"; }

    void addDepartment(const Department &d) { departments.push_back(d); }

    void displayCampusInfo() const
    {
        cout << "\n=== Campus: " << campusName << " | Location: " << location << " ===\n";
        for (const auto &d : departments)
            d.displayDepartmentInfo();
        library.displayLibraryInfo();
        hostel.displayHostelInfo();
    }
};

class University
{
private:
    vector<Campus> campuses;

public:
    string universityName;

    University() : universityName("Unknown") { cout << "Default constructor called for University\n"; }
    University(string uname) : universityName(uname) { cout << "Parameterized constructor called for University: " << universityName << "\n"; }

    ~University() { cout << "Destructor called for University: " << universityName << "\n"; }

    void addCampus(const Campus &c) { campuses.push_back(c); }

    void displayUniversityInfo() const
    {
        cout << "\n*** University: " << universityName << " ***\n";
        for (const auto &c : campuses)
            c.displayCampusInfo();
    }
};

class ViceChancellor
{
private:
    static ViceChancellor *instance;
    string name;
    int age;

    ViceChancellor(string n, int a) : name(n), age(a) { cout << "Vice Chancellor constructor called for " << name << "\n"; }

public:
    ViceChancellor(const ViceChancellor &) = delete;
    void operator=(const ViceChancellor &) = delete;

    static ViceChancellor *getInstance(string n = "Default VC", int a = 60)
    {
        if (!instance)
            instance = new ViceChancellor(n, a);
        else
            cout << "Vice Chancellor already exists, returning existing instance\n";
        return instance;
    }

    void displayVCInfo() const { cout << "Vice Chancellor: " << name << ", Age: " << age << endl; }

    ~ViceChancellor() { cout << "Vice Chancellor destructor called for " << name << "\n"; }
};
ViceChancellor *ViceChancellor::instance = nullptr;

int main()
{
    University uni("PUCIT");

    Department cs("Computer Science", "Dr. Ali");
    cs.addStudent(Student("Ahmed", 101, 3.2, 2, "CS"));
    cs.addStudent(Student("Sara", 102, 3.5, 4, "CS"));
    cs.addStudent(Student("Bilal", 103, 3.8, 6, "CS"));
    cs.addFaculty(Faculty("Prof. A", "Lecturer", "CS", 50000));
    cs.addFaculty(Faculty("Prof. B", "Assistant Prof", "CS", 70000));
    cs.addCourse(Course("PF", "CS101", 3, "Prof. A"));
    cs.addCourse(Course("OOP", "CS201", 4, "Prof. B"));

    Department it("Information Technology", "Dr. Khan");
    it.addStudent(Student("Hina", 104, 3.4, 2, "IT"));
    it.addStudent(Student("Usman", 105, 3.6, 4, "IT"));
    it.addStudent(Student("Omar", 106, 3.8, 6, "IT"));
    it.addFaculty(Faculty("Prof. C", "Lecturer", "IT", 55000));
    it.addFaculty(Faculty("Prof. D", "Assistant Prof", "IT", 75000));
    it.addCourse(Course("DS", "IT101", 3, "Prof. C"));
    it.addCourse(Course("AI", "IT201", 4, "Prof. D"));

    Campus c1("New Campus", "Lahore", Library("Central Library"), Hostel("Hostel A", 3));
    c1.addDepartment(cs);
    c1.addDepartment(it);
    uni.addCampus(c1);

    Department se("Software Engineering", "Dr. Sara");
    se.addStudent(Student("Ali", 201, 3.2, 2, "SE"));
    se.addStudent(Student("Fatima", 202, 3.5, 4, "SE"));
    se.addStudent(Student("Zain", 203, 3.7, 6, "SE"));
    se.addFaculty(Faculty("Prof. E", "Lecturer", "SE", 50000));
    se.addFaculty(Faculty("Prof. F", "Assistant Prof", "SE", 70000));
    se.addCourse(Course("DBMS", "SE101", 3, "Prof. E"));
    se.addCourse(Course("OS", "SE201", 4, "Prof. F"));

    Department ee("Electrical Engineering", "Dr. Ahmed");
    ee.addStudent(Student("Maryam", 204, 3.1, 2, "EE"));
    ee.addStudent(Student("Hassan", 205, 3.3, 4, "EE"));
    ee.addStudent(Student("Laiba", 206, 3.6, 6, "EE"));
    ee.addFaculty(Faculty("Prof. G", "Lecturer", "EE", 52000));
    ee.addFaculty(Faculty("Prof. H", "Assistant Prof", "EE", 75000));
    ee.addCourse(Course("Circuits", "EE101", 3, "Prof. G"));
    ee.addCourse(Course("Electronics", "EE201", 4, "Prof. H"));

    Campus c2("City Campus", "Lahore", Library("City Library"), Hostel("Hostel B", 3));
    c2.addDepartment(se);
    c2.addDepartment(ee);
    uni.addCampus(c2);


    uni.displayUniversityInfo();

    // --- Additional single student example ---
    // Department seSingle("SE", "Dr. Mian Mubasher");
    // seSingle.addStudent(Student("Waleed", 9, 3.9, 3, "SE"));
    // seSingle.displayDepartmentInfo();

     // Student s1("Waleed", -9, 3.9, 3, "IT");
    // s1.displayStudentInfo();

    return 0;
}



 
