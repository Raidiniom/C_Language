#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[20];

typedef struct {
    String fname;
    String lname;
} Name;

typedef struct 
{
    int studID;
    Name studName;
    bool sex; // true = male, false = female
    String program;
    int studYear;
} Student;

typedef struct {
    Student *studList;
    int max;
    int rear;
    int front;
} QueueADT;

Name createName(String fname, String lname);
Student createStudent(int id, Name studName, bool sex, String program, int studyear);

void initQueue(QueueADT *que, int max);
QueueADT createQueue(int max);

bool isEmpty(QueueADT que);
bool isFull(QueueADT que);
void makeEmpty(QueueADT *que);

bool enQue(QueueADT *que, Student stud);
bool deQue(QueueADT *que);
Student studFront(QueueADT que);

void displayT(QueueADT que);
void displayNT(QueueADT que);

#endif