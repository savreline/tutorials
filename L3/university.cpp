#include "university.h"

University::University() {
    students = vector<Student>();
}

void University::addStudent(Student s) {
    students.push_back(s);
}

void University::printRecords() {
    cout << "=== PRINTING ALL STUDENTS RECORDS ===" << endl;
    for (int i = 0; i < students.size(); i++) {
        students[i].printRecord();
    }
}

int main() {
    Student s1("Jane Doe", 1111, 90);
    Student s2("John Doe", 2222, 80);
    Student s3("Sasha", 3333, 85);

    s1.setGrade(105);
    s2.setGrade(96);
    // N.B. You will see that since we are not using pointers here
    // we have to call the setGrade methods prior to adding the
    // students to the university. 

    University u;
    u.addStudent(s1);
    u.addStudent(s2);
    u.addStudent(s3);
    u.printRecords();

    Point p = {10, 20};
    cout << "X: " << p.x << " Y: " << p.y << endl;
}
