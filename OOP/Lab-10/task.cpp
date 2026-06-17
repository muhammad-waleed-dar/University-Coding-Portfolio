#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


class Student {
public:
    int rollNo;
    string name;
    string department;
    float cgpa;
    int semester;

    void input() {
        cout << "Enter Roll No: "; cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Department: "; getline(cin, department);
        cout << "Enter CGPA: "; cin >> cgpa;
        cout << "Enter Semester: "; cin >> semester;
    }

    void display() {
        cout << rollNo << " " << name << " " << department
             << " " << cgpa << " " << semester << "\n";
    }
};

class Faculty {
public:
    int facultyID;
    string name;
    string designation;
    string department;
    string qualification;

    void input() {
        cout << "Enter Faculty ID: "; cin >> facultyID;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Designation: "; getline(cin, designation);
        cout << "Enter Department: "; getline(cin, department);
        cout << "Enter Qualification: "; getline(cin, qualification);
    }

    void display() {
        cout << facultyID << " " << name << " " << designation
             << " " << department << " " << qualification << "\n";
    }
};

class Course {
public:
    string courseCode;
    string title;
    int creditHours;
    string department;
    int semester;

    void input() {
        cin.ignore();
        cout << "Enter Course Code: "; getline(cin, courseCode);
        cout << "Enter Title: "; getline(cin, title);
        cout << "Enter Credit Hours: "; cin >> creditHours;
        cin.ignore();
        cout << "Enter Department: "; getline(cin, department);
        cout << "Enter Semester: "; cin >> semester;
    }

    void display() {
        cout << courseCode << " " << title << " " << creditHours
             << " " << department << " " << semester << "\n";
    }
};

class Enrollment {
public:
    int teacherID;
    string teacherName;
    string courseCode;
    string courseTitle;
    int studentCount;
    vector<Student> students;

    void input() {
        cout << "Enter Teacher ID: "; cin >> teacherID;
        cin.ignore();
        cout << "Enter Teacher Name: "; getline(cin, teacherName);
        cout << "Enter Course Code: "; getline(cin, courseCode);
        cout << "Enter Course Title: "; getline(cin, courseTitle);
        cout << "Enter Number of Students: "; cin >> studentCount;
        students.clear();
        for (int i = 0; i < studentCount; i++) {
            cout << "---- Student " << (i+1) << " ----\n";
            Student s;
            s.input();
            students.push_back(s);
        }
    }

    void display() {
        cout << "TeacherID: " << teacherID << ", TeacherName: " << teacherName
             << ", CourseCode: " << courseCode << ", CourseTitle: " << courseTitle
             << ", StudentCount: " << studentCount << "\n";
        for (auto &s : students) s.display();
        cout << "---------------------------\n";
    }

    void writeText(ofstream &fout) {
        fout << teacherID << "," << teacherName << "," << courseCode << "," << courseTitle << "," << studentCount << "\n";
        for (auto &s : students) {
            fout << s.rollNo << "," << s.name << "," << s.semester << "," << s.department << "," << s.cgpa << "\n";
        }
        fout << "\n";
    }

    void readText(ifstream &fin) {
        string line, temp;
        getline(fin, line);
        if (line.empty()) return;
        stringstream ss(line);
        getline(ss, temp, ','); teacherID = stoi(temp);
        getline(ss, teacherName, ',');
        getline(ss, courseCode, ',');
        getline(ss, courseTitle, ',');
        getline(ss, temp, ','); studentCount = stoi(temp);

        students.clear();
        for (int i = 0; i < studentCount; i++) {
            getline(fin, line);
            stringstream sss(line);
            Student s;
            getline(sss, temp, ','); s.rollNo = stoi(temp);
            getline(sss, s.name, ',');
            getline(sss, temp, ','); s.semester = stoi(temp);
            getline(sss, s.department, ',');
            getline(sss, temp, ','); s.cgpa = stof(temp);
            students.push_back(s);
        }
        getline(fin, line); 
    }


    void writeBinary(ofstream &fout) {
        fout.write((char*)&teacherID, sizeof(teacherID));
        int len = teacherName.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(teacherName.c_str(), len);
        len = courseCode.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(courseCode.c_str(), len);
        len = courseTitle.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(courseTitle.c_str(), len);
        fout.write((char*)&studentCount, sizeof(studentCount));
        for (auto &s : students) {
            fout.write((char*)&s.rollNo, sizeof(s.rollNo));
            len = s.name.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(s.name.c_str(), len);
            len = s.department.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(s.department.c_str(), len);
            fout.write((char*)&s.cgpa, sizeof(s.cgpa));
            fout.write((char*)&s.semester, sizeof(s.semester));
        }
    }

    void readBinary(ifstream &fin) {
        fin.read((char*)&teacherID, sizeof(teacherID));
        int len;
        char buffer[100];
        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len); buffer[len]='\0'; teacherName = buffer;
        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len); buffer[len]='\0'; courseCode = buffer;
        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len); buffer[len]='\0'; courseTitle = buffer;
        fin.read((char*)&studentCount, sizeof(studentCount));
        students.clear();
        for(int i=0;i<studentCount;i++){
            Student s;
            fin.read((char*)&s.rollNo, sizeof(s.rollNo));
            fin.read((char*)&len, sizeof(len));
            fin.read(buffer, len); buffer[len]='\0'; s.name = buffer;
            fin.read((char*)&len, sizeof(len));
            fin.read(buffer, len); buffer[len]='\0'; s.department = buffer;
            fin.read((char*)&s.cgpa, sizeof(s.cgpa));
            fin.read((char*)&s.semester, sizeof(s.semester));
            students.push_back(s);
        }
    }
};


void addEnrollmentText() {
    Enrollment e;
    e.input();
    ofstream fout("enrollments.txt", ios::app);
    e.writeText(fout);
    fout.close();
    cout << "Enrollment added in TEXT file.\n";
}

void displayEnrollmentsText() {
    ifstream fin("enrollments.txt");
    if(!fin){ cout << "No TEXT file found.\n"; return;}
    while(fin.peek()!=EOF){
        Enrollment e;
        e.readText(fin);
        if(!fin.eof()) e.display();
    }
    fin.close();
}

void addEnrollmentBinary() {
    Enrollment e;
    e.input();
    ofstream fout("enrollments.bin", ios::binary | ios::app);
    e.writeBinary(fout);
    fout.close();
    cout << "Enrollment added in BINARY file.\n";
}

void displayEnrollmentsBinary() {
    ifstream fin("enrollments.bin", ios::binary);
    if(!fin){ cout << "No BINARY file found.\n"; return;}
    while(fin.peek()!=EOF){
        Enrollment e;
        e.readBinary(fin);
        if(!fin.eof()) e.display();
    }
    fin.close();
}


int main() {
    int choice;
    do{
        cout << "\n--- UCMS Menu ---\n";
        cout << "1. Add Enrollment (TEXT)\n";
        cout << "2. Display Enrollments (TEXT)\n";
        cout << "3. Add Enrollment (BINARY)\n";
        cout << "4. Display Enrollments (BINARY)\n";
        cout << "5. Exit\nChoice: ";
        cin >> choice;

        switch(choice){
            case 1: addEnrollmentText(); break;
            case 2: displayEnrollmentsText(); break;
            case 3: addEnrollmentBinary(); break;
            case 4: displayEnrollmentsBinary(); break;
        }
    }while(choice!=5);
    cout << "Exiting UCMS...\n";
    return 0;
}
