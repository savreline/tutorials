// voidPnt.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include "stdio.h"

typedef struct Student {
    char **first_name;
    char **last_name;
    int *year;
    int *gpa;
    int *id;
} Student;
char *fields[] = {"FirstName", "LastName", "Year", "GPA"};
enum FIELDS {FIRSTNAME = 0, LASTNAME = 1, YEAR = 2, GPA = 3};

void setFirstName(Student *s, void *fn) {
    s->first_name = (char **)fn;
}  

void setLastName(Student *s, void *ln) {
    s->last_name = (char **)ln;
}

void setYear(Student *s, void *year) {
    s->year = (int *)year;
}

void setGpa(Student *s, void *gpa) {
    s->gpa = (int *)gpa;
}

typedef void (*FunctionTemplate)(Student *s, void *val);
FunctionTemplate functions_array[] = {setFirstName, setLastName, setYear, setGpa};

void setField(int i, Student *s, void *val) {
    printf("Changing %s for student no: %d.\n", fields[i], *(s->id));
    functions_array[i](s, val);
    printf("Procedure %s completed for student no: %d.\n", fields[i], *(s->id));
}

int main() {
    char *fn = "John";
    char *ln = "Doe";
    int year = 2;
    int gpa = 80;
    int id = 9999;
    Student s = {&fn, &ln, &year, &gpa, &id};

    char *new_name = "Jane";
    setField(FIRSTNAME, &s, &new_name);
    printf("%s\n", *(s.first_name));

    int new_year = 3;
    setField(YEAR, &s, &new_year);
    printf("%d\n", *(s.year));

    int new_gpa = 90;
    setField(GPA, &s, &new_gpa);
    printf("%d\n", *(s.gpa));

    return 0;
}
