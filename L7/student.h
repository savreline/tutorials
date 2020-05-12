#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct Student {
    private:
        string name;
        int id;
        int grade;
        bool validGrade(int grade);

    public:
        Student(string name, int id, int grade);
        string getName();
        int getId();
        int getGrade();
        void setGrade(int newGrade);
        void printRecord();
};

#endif
