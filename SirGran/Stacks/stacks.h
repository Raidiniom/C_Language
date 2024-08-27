#ifndef STACKS_H
#define STACKS_H

#include <stdbool.h>
#include <string.h>
#include "student.h"
#define MAX 10

typedef struct 
{
    Student list[MAX];
    int count;
} Stacks;

Stacks createStack();

void initStack(Stacks *s);
bool isEmpty(Stacks s);
bool isFull(Stacks s);

void display(Stacks s);

bool push(Stacks *s, Student elem);
bool pop(Stacks *s);
Student peek(Stacks s);

// Stacks findEven(Stacks origin);

Stacks getStudent(Stacks origin, String program);
void arrangeStudent(Stacks *origin);

#endif