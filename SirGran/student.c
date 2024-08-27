#include <stdio.h>
#include <string.h>
#include "student.h"
#include "stacks.h"

Student createStud(int id, String name, String program) {
    Student newStud;

    newStud.studID = id;
    strcpy(newStud.studName, name);
    strcpy(newStud.program, program);

    return newStud;
}