#include <iostream>
#include <string.h>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    float price;
    bool isIssued;

public:
    Book() : bookID(0), title(""), author(""), price(0.0), isIssued(false) 
    {
    }

    Book(int id, string t, string a, float p) : bookID(id), title(t), author(a), price(p), isIssued(false) 
    {
    }

    
    Book(const Book &b)
    {
        bookID = b.bookID;
        title = b.title;
        author = b.author;
        price = b.price;
        isIssued = b.isIssued;
        cout << "Book copied: " << title << endl;
    }

    ~Book() 
    {
        cout << "Book destroyed: " << title << endl;
    }

    void displayBook() {
        cout << "BookID: " << bookID << ", Title: " << title << ", Author: " << author << ", Price: " << price << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }

    bool issueBook() 
    {
        if (!isIssued) 
        {
            isIssued = true;
            return true;
        }
        return false; 
    }

    void returnBook() 
    { isIssued = false; 
    }

    bool getStatus() const 
    { return isIssued; 
    }

    void updatePrice(float p) 
    { price = p; 
    }

    int getBookID() const 
    { return bookID; 
    }

    string getTitle() const 
    { return title; 
    }

    float getPrice() const 
    { return price; 
    }

    bool operator==(const Book &b) const 
    { 
        return bookID == b.bookID; 
    }

    float operator+(const Book &b) const 
    { 
        return price + b.price; 
    }

    friend ostream& operator<<(ostream &out, const Book &b) 
    {
        out << "BookID: " << b.bookID << ", Title: " << b.title << ", Author: " << b.author << ", Price: " << b.price << ", Issued: " << (b.isIssued ? "Yes" : "No");
        return out;
    }
    
};

class Course {
private:
    int courseID;
    string courseName;
    float fee;
    int maxStudents;
    int enrolledCount;

public:
    Course() : courseID(0), courseName(""), fee(0), maxStudents(0), enrolledCount(0) 
    {

    }

    Course(int id, string name, float f, int maxS) : courseID(id), courseName(name), fee(f), maxStudents(maxS), enrolledCount(0) 
    {

    }

    Course(const Course &c) {
        courseID = c.courseID;
        courseName = c.courseName;
        fee = c.fee;
        maxStudents = c.maxStudents;
        enrolledCount = c.enrolledCount;
        cout << "Course copied: " << courseName << endl;
    }

    ~Course() {
        cout << "Course destroyed: " << courseName << endl;
    }

    void enrollStudent() 
    {
        if (enrolledCount < maxStudents) 
        {
            enrolledCount++;
        }
    }

    void dropStudent() 
    {
        if (enrolledCount > 0) 
        enrolledCount--;
    }

    void displayCourse() const 
    {
        cout << "CourseID: " << courseID << ", Name: " << courseName << ", Fee: " << fee << ", Enrolled: " << enrolledCount << ", Max students: " << maxStudents << endl;
    }

    int getCourseID() const 
    { return courseID; }

    string getCourseName() const 
    { return courseName; }

    float getFee() const 
    { return fee; }

    bool operator==(const Course &c) const 
    { return courseID == c.courseID; }

};

class Person {
private:
    string name;
    int id;

public:
    void inputInfo() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
    }

    void showInfo() const 
    {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    string getName() const 
    { return name; }

    int getID() const 
    { return id; }

    void setName(string n) 
    { name = n; }
    
    void setID(int i) 
    { id = i; }
};

class Student : public Person
{
private:
    string department;
    Book* issuedBooks[5];
    Course* enrolledCourses[3];
    int issuedBooksCount;
    int enrolledCoursesCount;

public:
    static int totalStudents;
    static int totalBooksIssued;


    Student() : department(""), issuedBooksCount(0), enrolledCoursesCount(0) 
    {   for (int i = 0; i < 5; i++) 
        issuedBooks[i] = nullptr; 

        for (int i = 0; i < 3; i++) 
        enrolledCourses[i] = nullptr; 

        totalStudents++; 
    }

    ~Student()
    {
        totalStudents--;
        cout << "Student destroyed: " << getName() << endl;
    }

    void setDepartment(string d) 
    { department = d; }

    string getDepartment() const 
    { return department; }

    void issueBook(Book* b)
    {
        if(issuedBooksCount < 5 && b->issueBook())
        {
            issuedBooks[issuedBooksCount++] = b;
            totalBooksIssued++;
        }
    }

    void enrollCourse(Course* c)
    {
        if(enrolledCoursesCount < 3)
        {
            enrolledCourses[enrolledCoursesCount++] = c;
            c->enrollStudent();
        }
    }

    void displayBooks() const
    {
        for(int i = 0; i < issuedBooksCount; i++)
        {
            if(issuedBooks[i] != nullptr)
                issuedBooks[i]->displayBook();
        }
    }

    void displayCourses() const
    {
        for(int i = 0; i < enrolledCoursesCount; i++)
        {
            if(enrolledCourses[i] != nullptr)
                enrolledCourses[i]->displayCourse();
        }
    }

    float computeTotalFees() const
    {
        float sum = 0;
        for(int i = 0; i < issuedBooksCount; i++)
            if(issuedBooks[i] != nullptr)
                sum += issuedBooks[i]->getPrice();

        for(int i = 0; i < enrolledCoursesCount; i++)
            if(enrolledCourses[i] != nullptr)
                sum += enrolledCourses[i]->getFee();

        return sum;
    }
};

int Student::totalStudents = 0;
int Student::totalBooksIssued = 0;

int main() {
    Book* b1 = new Book(1, "C++", "Author A", 500);
    Book* b2 = new Book(2, "OOP", "Author B", 700);
    Book* b3 = new Book(3, "DSA", "Author C", 600);
    Book* b4 = new Book(4, "Database", "Author D", 800);

    Course* c1 = new Course(1, "Programmming", 1500, 2);
    Course* c2 = new Course(2, "Data sttructures", 2000, 2);
    Course* c3 = new Course(3, "DB", 1800, 2);

    Student* s1 = new Student();
    s1->setName("Ali"); 
    s1->setID(1); 
    s1->setDepartment("CS");

    Student* s2 = new Student();
    s2->setName("Waleed");
    s2->setID(2); 
    s2->setDepartment("IT");

    Student* s3 = new Student();
    s3->setName("Ahmed"); 
    s3->setID(3); 
    s3->setDepartment("SE");

    s1->issueBook(b1); 
    s1->issueBook(b2);
    s2->issueBook(b3); 
    s2->issueBook(b4);

    s1->enrollCourse(c1); 
    s1->enrollCourse(c2);
    s2->enrollCourse(c1); 
    s2->enrollCourse(c3);
    s3->enrollCourse(c2); 
    s3->enrollCourse(c3);

    s1->displayBooks(); 
    s1->displayCourses();
    cout << s1->getName() << "'s total fees: " << s1->computeTotalFees() << endl;

    s2->displayBooks(); 
    s2->displayCourses();
    cout << s2->getName() << "'s total fees: " << s2->computeTotalFees() << endl;

    s3->displayBooks(); 
    s3->displayCourses();
    cout << s3->getName() << "'s total fees: " << s3->computeTotalFees() << endl;

    float sum = *b1 + *b2;
    cout << "Sum of book prices: " << sum << endl;

    if (*b1 == *b2)
    cout << "Books are same" << endl;
    else 
    cout << "Books are different" << endl;

    cout << "Total students: " << Student::totalStudents << endl;
    cout << "Total books issued: " << Student::totalBooksIssued << endl;

    return 0;

}