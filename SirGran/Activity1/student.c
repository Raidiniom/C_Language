#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

Name createName(String fname, String lname) {
    Name initName;

    strcpy(initName.fname, fname);
    strcpy(initName.lname, lname);

    return initName;
}

Student createStudent(int id, Name student_name, Sex sex, String program) {
    Student initStudent;

    initStudent.Stud_id = id;
    initStudent.Stud_name = student_name;
    initStudent.Stud_sex = sex;
    strcpy(initStudent.Stud_program, program);

    return initStudent;
}