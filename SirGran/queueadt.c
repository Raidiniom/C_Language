#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueadt.h"

//  =====Helps Creating the Student Details=====
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
// ========================================

// Initialize the Queue
QueueADT createQueue(int max) {
    QueueADT initQue;

    initQue.max = max;
    initQue.studList = malloc(sizeof(Student) * max);
    initQue.front = 1;
    initQue.rear = 0;

    return initQue;
}

// Check if the Queue is Empty or not
bool isEmpty(QueueADT que) {
    return (que.rear + 1) % que.max == que.front;
}

// Check if the Queue is Full or not
bool isFull(QueueADT que) {
    return (que.rear + 2) % que.max == que.front;
}

// Empties the list
void makeEmpty(QueueADT *que) {
    que->front = 1;
    que->rear = 0;
}

// Insert_Rear
bool enQue(QueueADT *que, Student stud) {
    if (!isFull(*que))
    {
        que->rear = (que->rear + 1) % que->max;

        que->studList[que->rear] = stud;

        return true;
    }
    return false;
}

// Delete_Front
bool deQue(QueueADT *que) {
    if (!isEmpty(*que))
    {
        que->front = (que->front + 1) % que->max;

        return true;
    }
    return false;
}

Student studFront(QueueADT que) {
    return que.studList[que.front];
}

// Traversing through the Array
void displayT(QueueADT que) {
    printf("%s%5s%s%5s%s\n", "Index", " ", "Full Name", " ", "Program");
    for (int i = 0; i <= que.rear; i++)
    {
        printf("%d%8s%s, %s%5s%s\n", i," ", que.studList[i].studName.fname, que.studList[i].studName.lname, " ", que.studList[i].program);
    }
}

// Using Enqueue and Dequeue to display the queue
void displayNT(QueueADT que) {
    // int rear = que.rear;
    // Student hold;

    // printf("Non-Traversal:\n");
    // while (rear != 0)
    // {
    //     hold = que.studList[rear];
    //     printf("%s %s %s %s\n", hold.studName.fname, hold.studName.lname, hold.program, (hold.sex) ? "Male":"Female");
    //     deQue(&que);
    //     rear--;
    // }
    // ^ Old Solution ^

    Student temp;
    while (!isEmpty(que))
    {
        temp = studFront(que);
        printf("%s %s %s %s\n", temp.studName.fname, temp.studName.lname, temp.program, (temp.sex) ? "Male":"Female");
        deQue(&que);
    }
    // ^ New Solution ^
}