#include <iostream>
#include <string>
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

    void setRollNo(int r) { 
    if (r <= 0) {
        cout << "Invalid Roll No! Setting default.\n";
        rollNo = 1;
    } else {
        rollNo = r;
    }
}

    int getRollNo() const
    {
        return rollNo;
    }
    void setGPA(float g) { 
    if (g < 0.0 || g > 4.0) {
        cout << "Invalid GPA! Setting default.\n";
        GPA = 0.0;
    } else {
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
    Student students[3];
    Faculty faculty[2];
    Course courses[2];

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

    void addStudent(int i, const Student &s) { students[i] = s; }
    void addFaculty(int i, const Faculty &f) { faculty[i] = f; }
    void addCourse(int i, const Course &c) { courses[i] = c; }

    void displayDepartmentInfo() const
    {
        cout << "\nDepartment: " << departmentName << " | HOD: " << hodName << endl;
        cout << "-- Students --\n";
        for (int i = 0; i < 3; i++)
            students[i].displayStudentInfo();
        cout << "-- Faculty --\n";
        for (int i = 0; i < 2; i++)
            faculty[i].displayFacultyInfo();
        cout << "-- Courses --\n";
        for (int i = 0; i < 2; i++)
            courses[i].displayCourseInfo();
    }
};

class Library
{
private:
    string issuedBooks[3];

public:
    string libraryName;

    Library() : libraryName("Unknown")
    {
        cout << "Default constructor called for Library\n";
    }

    Library(string lname) : libraryName(lname)
    {
        cout << "Parameterized constructor called for Library: " << libraryName << "\n";
    }

    ~Library()
    {
        cout << "Destructor called for Library: " << libraryName << "\n";
    }

    void issueBook(const Student &s)
    {
        for (int i = 0; i < 3; i++)
        {
            if (issuedBooks[i] == "")
            {
                issuedBooks[i] = s.name;
                cout << "Book issued to " << s.name << endl;
                return;
            }
        }
        cout << "Library full!\n";
    }

    void displayLibraryInfo() const
    {
        cout << "\nLibrary: " << libraryName << endl;
        for (int i = 0; i < 3; i++)
            if (issuedBooks[i] != "")
                cout << "Issued to: " << issuedBooks[i] << endl;
    }
};

class Hostel
{
private:
    Student stayingStudents[3];

public:
    string hostelName;
    int capacity;

    Hostel() : hostelName("None"), capacity(0)
    {
        cout << "Default constructor called for Hostel\n";
    }

    Hostel(string hname, int cap) : hostelName(hname), capacity(cap)
    {
        cout << "Parameterized constructor called for Hostel: " << hostelName << "\n";
    }

    ~Hostel()
    {
        cout << "Destructor called for Hostel: " << hostelName << "\n";
    }

    void assignRoom(const Student &s)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (stayingStudents[i].name == "")
            {
                stayingStudents[i] = s;
                cout << s.name << " assigned in " << hostelName << endl;
                return;
            }
        }
        cout << "Hostel full!\n";
    }

    void displayHostelInfo() const
    {
        cout << "\nHostel: " << hostelName << " | Capacity: " << capacity << endl;
        for (int i = 0; i < capacity; i++)
            if (stayingStudents[i].name != "")
                cout << "Staying: " << stayingStudents[i].name << endl;
    }
};

class Campus
{
private:
    Department departments[2];
    Library library;
    Hostel hostel;

public:
    string campusName, location;

    Campus() : campusName("Unknown"), location("Unknown")
    {
        cout << "Default constructor called for Campus\n";
    }

    Campus(string cname, string loc, Department d1, Department d2, Library l, Hostel h)
        : campusName(cname), location(loc), library(l), hostel(h)
    {
        departments[0] = d1;
        departments[1] = d2;
        cout << "Parameterized constructor called for Campus: " << campusName << "\n";
    }

    ~Campus()
    {
        cout << "Destructor called for Campus: " << campusName << "\n";
    }

    void displayCampusInfo() const
    {
        cout << "\n=== Campus: " << campusName << " | Location: " << location << " ===\n";
        departments[0].displayDepartmentInfo();
        departments[1].displayDepartmentInfo();
        library.displayLibraryInfo();
        hostel.displayHostelInfo();
    }
};

class University
{
private:
    Campus campuses[2];

public:
    string universityName;

    University() : universityName("Unknown")
    {
        cout << "Default constructor called for University\n";
    }

    University(string uname) : universityName(uname)
    {
        cout << "Parameterized constructor called for University: " << universityName << "\n";
    }

    ~University()
    {
        cout << "Destructor called for University: " << universityName << "\n";
    }

    void addCampus(int i, Campus c) { campuses[i] = c; }

    void displayUniversityInfo() const
    {
        cout << "\n*** University: " << universityName << " ***\n";
        for (int i = 0; i < 2; i++)
            campuses[i].displayCampusInfo();
    }
};

class ViceChancellor
{
private:
    static ViceChancellor *instance;
    string name;
    int age;

    ViceChancellor(string n, int a) : name(n), age(a)
    {
        cout << "Vice Chancellor constructor called for " << name << "\n";
    }

public:
    ViceChancellor(const ViceChancellor &) = delete;
    void operator=(const ViceChancellor &) = delete;

    static ViceChancellor *getInstance(string n = "Default VC", int a = 60)
    {
        if (instance == nullptr)
        {
            instance = new ViceChancellor(n, a);
        }
        else
        {
            cout << "Vice Chancellor already exists, returning existing instance\n";
        }
        return instance;
    }

    void displayVCInfo() const
    {
        cout << "Vice Chancellor: " << name << ", Age: " << age << endl;
    }
    ~ViceChancellor()
    {
        cout << "Vice Chancellor destructor called for " << name << "\n";
    }
};

ViceChancellor *ViceChancellor::instance = nullptr;

int main()
{
    University uni("PUCIT");

    Department cs("Computer Science", "Dr. Ali");
    cs.addStudent(0, Student("Ahmed", 101, 3.2, 2, "CS"));
    cs.addStudent(1, Student("Sara", 102, 3.5, 4, "CS"));
    cs.addStudent(2, Student("Bilal", 103, 3.8, 6, "CS"));
    cs.addFaculty(0, Faculty("Prof. A", "Lecturer", "CS", 50000));
    cs.addFaculty(1, Faculty("Prof. B", "Assistant Prof", "CS", 70000));
    cs.addCourse(0, Course("PF", "CS101", 3, "Prof. A"));
    cs.addCourse(1, Course("OOP", "CS201", 4, "Prof. B"));

    Department it("Information Technology", "Dr. Khan");
    it.addStudent(0, Student("Hina", 104, 3.4, 2, "IT"));
    it.addStudent(1, Student("Usman", 105, 3.6, 4, "IT"));
    it.addStudent(2, Student("Omar", 106, 3.8, 6, "IT"));
    it.addFaculty(0, Faculty("Prof. C", "Lecturer", "IT", 55000));
    it.addFaculty(1, Faculty("Prof. D", "Assistant Prof", "IT", 75000));
    it.addCourse(0, Course("DS", "IT101", 3, "Prof. C"));
    it.addCourse(1, Course("AI", "IT201", 4, "Prof. D"));

    Campus c1("New Campus", "Lahore", cs, it, Library("Central Library"), Hostel("Hostel A", 3));
    uni.addCampus(0, c1);

    Department se("Software Engineering", "Dr. Sara");
    se.addStudent(0, Student("Ali", 201, 3.2, 2, "SE"));
    se.addStudent(1, Student("Fatima", 202, 3.5, 4, "SE"));
    se.addStudent(2, Student("Zain", 203, 3.7, 6, "SE"));
    se.addFaculty(0, Faculty("Prof. E", "Lecturer", "SE", 50000));
    se.addFaculty(1, Faculty("Prof. F", "Assistant Prof", "SE", 70000));
    se.addCourse(0, Course("DBMS", "SE101", 3, "Prof. E"));
    se.addCourse(1, Course("OS", "SE201", 4, "Prof. F"));

    Department ee("Electrical Engineering", "Dr. Ahmed");
    ee.addStudent(0, Student("Maryam", 204, 3.1, 2, "EE"));
    ee.addStudent(1, Student("Hassan", 205, 3.3, 4, "EE"));
    ee.addStudent(2, Student("Laiba", 206, 3.6, 6, "EE"));
    ee.addFaculty(0, Faculty("Prof. G", "Lecturer", "EE", 52000));
    ee.addFaculty(1, Faculty("Prof. H", "Assistant Prof", "EE", 75000));
    ee.addCourse(0, Course("Circuits", "EE101", 3, "Prof. G"));
    ee.addCourse(1, Course("Electronics", "EE201", 4, "Prof. H"));

    Campus c2("City Campus", "Lahore", se, ee, Library("City Library"), Hostel("Hostel B", 3));
    uni.addCampus(1, c2);

    uni.displayUniversityInfo();

    // Department se("SE", "Dr. Mian Mubasher");
    // se.addStudent(0, Student("Waleed", 9, 3.9, 3, "SE"));

    // Student s1("Waleed", -9, 3.9, 3, "IT");
    // s1.displayStudentInfo();

    return 0;
}
