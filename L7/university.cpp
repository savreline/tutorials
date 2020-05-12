#include "university.h"

University::University() {
    students = vector<Student *>();
}

University::~University() {
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

void University::addStudent(Student *s) {
    students.push_back(s);
}

void University::printRecords() {
    cout << "=== PRINTING ALL STUDENTS RECORDS ===" << endl;
    for (int i = 0; i < students.size(); i++) {
        students[i]->printRecord();
    }
}

University buildUniversity() {
    Student *s1 = new Student("Jane Doe", 1111, 90);
    Student *s2 = new Student("John Doe", 2222, 80);
    Student *s3 = new Student("Sasha", 3333, 85);

    University u;
    u.addStudent(s1);
    u.addStudent(s2);
    u.addStudent(s3);

    s1->setGrade(105);
    s2->setGrade(96);
    return u;
}

int main() {
    University u = buildUniversity();
    u.printRecords();
}
