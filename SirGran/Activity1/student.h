#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>

typedef char String[10];

typedef struct 
{
    String fname;
    String lname;
} Name;

typedef enum 
{
    female,
    male
} Sex;

typedef struct 
{
    int Stud_id;
    Name Stud_name;
    Sex Stud_sex;
    String Stud_program;
} Student;

Name createName(String fname, String lname);
Student createStudent(int ID, Name student_name, Sex sex, String program);


#endif