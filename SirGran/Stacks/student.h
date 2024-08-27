#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>
#include "stacks.h"
#define MAX 10

typedef char String[MAX];

typedef struct {
    int studID;
    String studName;
    String program;
} Student;

Student createStud(int id, String name, String program);

#endif