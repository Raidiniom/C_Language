#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "closehash.h"

Student createStudent(int id, String name, String program, int year) {
    Student start;
    
    start.stud_id = id;
    strcpy(start.stud_name, name);
    strcpy(start.program, program);
    start.year = year;
    
    return start;
}

int getHash(Student stud) {
    int sum = 0, check;

    for (int i = 32; i != 0; i--)
    {
        check = stud.stud_id >> i;

        sum += i;
    }
    

    return sum % MAX;
}