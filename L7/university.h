#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

struct University {
    private:
        vector<Student *> students;

    public:
        University();
        ~University();
        void addStudent(Student *s);
        void printRecords();
};

#endif
