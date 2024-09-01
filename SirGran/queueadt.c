#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueadt.h"

//  Helps Creating the Student Details
Name createName(String fname, String lname) {
    Name initName;

    strcpy(initName.fname, fname);
    strcpy(initName.lname, lname);

    return initName;
}

Student createStudent(int id, Name studName, bool sex, String program, int studyear) {
    Student initStudent;

    initStudent.studID = id;
    initStudent.studName = studName;
    initStudent.sex = sex;
    strcpy(initStudent.program, program);
    initStudent.studYear = studyear;

    return initStudent;
}

void initQueue(QueueADT *que, int max) {
    que->max = max;
    que->studList = malloc(sizeof(Student) * max);
    que->front = 1;
    que->rear = 0;
}

QueueADT createQueue(int max) {
    QueueADT initQue;

    initQue.max = max;
    initQue.studList = malloc(sizeof(Student) * max);
    initQue.front = 1;
    initQue.rear = 0;

    return initQue;
}

// 
bool isEmpty(QueueADT que) {
    return (que.rear + 1) % que.max == que.front;
}
bool isFull(QueueADT que) {
    return (que.rear + 2) % que.max == que.front;
}
void makeEmpty(QueueADT *que);

// 
bool enQue(QueueADT *que, Student stud) {
    if (!isFull(*que))
    {
        que->rear = (que->rear + 1) % que->max;
        que->front = (que->front + 2) % que->max;

        que->studList[++(que->rear)] = stud;

        return true;
    }
    return false;
}
bool deQue(QueueADT *que);
Student studFront(QueueADT que);

// 
void displayT(QueueADT que) {
    printf("Index | Name\n");
    for (int i = 0; i < que.max; i++)
    {
        printf("%d   %s\n", i, que.studList[i].studName.fname);
    }
}
void displayNT(QueueADT que);