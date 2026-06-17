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

    Student(string n = "", int r = 0, float g = 0.0, int sem = 0, string dept = "")
    {
        name = n;
        rollNo = r;
        GPA = g;
        semester = sem;
        departmentName = dept;
    }

    void setRollNo(int r) { rollNo = r; }
    int getRollNo() const {
        // rollNo = 2; 
        return rollNo; 
    }

    void setGPA(float g) { GPA = g; }
    float getGPA() { return GPA; }

    void setCNIC(string c) { CNIC = c; }
    string getCNIC() { return CNIC; }

    void displayStudentInfo()
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

    Faculty(string n = "", string des = "", string dept = "", float s = 0)
    {
        name = n;
        designation = des;
        departmentName = dept;
        salary = s;
    }

    void setSalary(float s) { salary = s; }
    float getSalary() { return salary; }

    void displayFacultyInfo()
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

    Course(string cname = "", string code = "", int ch = 0, string inst = "")
    {
        courseName = cname;
        courseCode = code;
        creditHours = ch;
        instructorName = inst;
    }

    void displayCourseInfo()
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

    Department(string dname = "", string hod = "")
    {
        departmentName = dname;
        hodName = hod;
    }

    void addStudent(int i, Student s) { students[i] = s; }
    void addFaculty(int i, Faculty f) { faculty[i] = f; }
    void addCourse(int i, Course c) { courses[i] = c; }

    void displayDepartmentInfo()
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

    Library(string lname = "") { libraryName = lname; }

    void issueBook(Student s)
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
    void returnBook(Student s)
    {
        for (int i = 0; i < 3; i++)
        {
            if (issuedBooks[i] == s.name)
            {
                issuedBooks[i] = "";
                cout << s.name << " returned book\n";
                return;
            }
        }
        cout << "No book found for " << s.name << endl;
    }
    void calculateFine(Student s) { cout << "Fine for " << s.name << ": Rs.100\n"; }

    void displayLibraryInfo()
    {
        cout << "\nLibrary: " << libraryName << endl;
        for (int i = 0; i < 3; i++)
            if (issuedBooks[i] != "")
                cout << "Issued: " << issuedBooks[i] << endl;
    }
};

class Hostel
{
private:
    Student stayingStudents[3];

public:
    string hostelName;
    int capacity;

    Hostel(string hname = "", int cap = 3)
    {
        hostelName = hname;
        capacity = cap;
    }

    void assignRoom(Student s)
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
    void vacateRoom(Student s)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (stayingStudents[i].name == s.name)
            {
                stayingStudents[i].name = "";
                cout << s.name << " vacated from " << hostelName << endl;
                return;
            }
        }
        cout << s.name << " not found in hostel\n";
    }
    void displayHostelInfo()
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

    Campus(string cname = "", string loc = "", Department d1 = Department(), Department d2 = Department(),
           Library l = Library(), Hostel h = Hostel())
    {
        campusName = cname;
        location = loc;
        departments[0] = d1;
        departments[1] = d2;
        library = l;
        hostel = h;
    }

    void displayCampusInfo()
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

    University(string uname = "") { universityName = uname; }

    void addCampus(int i, Campus c) { campuses[i] = c; }

    void displayUniversityInfo()
    {
        cout << "\n*** University: " << universityName << " ***\n";
        for (int i = 0; i < 2; i++)
            campuses[i].displayCampusInfo();
    }
};

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

    return 0;
}
