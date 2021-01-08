#include "student.h"

Student::Student(string name, int id, int grade) {
    this->name = name;
    this->id = id;
    if (validGrade(grade))
        this->grade = grade;
}

string Student::getName() {
    return name;
}

int Student::getId() {
    return id;
}

int Student::getGrade() {
    return grade;
}

void Student::setGrade(int newGrade) {
    if (validGrade(newGrade))
        grade = newGrade;
}

void Student::printRecord() {
    cout << "PRINTING RECORD for student " << name 
        << " with ID " << id 
        << " grade is " << grade << endl; 
}

bool Student::validGrade(int grade) {
    if (grade >= 0 && grade <= 100) {
        return true;
    } else {
        cout << "Invalid grade for student: " << name << endl;
        return false;
    }
}
