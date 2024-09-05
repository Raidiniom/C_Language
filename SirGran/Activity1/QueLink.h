#ifndef QUELINK_H
#define QUELINK_H

#include <stdbool.h>
#include "student.h"


typedef Student Data;

typedef struct node 
{
    Data Elem;
    struct node *next;
} NodeType, *NodePTR;

typedef struct 
{
    NodePTR head;
    NodePTR tail;
} Queue;

// Main Functions
Queue createQueue();

bool isEmpty(Queue q);

void debugQueue(Queue q);
void visualizeQueue(Queue q);

bool enQueue(Queue *q, Data d);
bool deQueue(Queue *q);

Data front(Queue q);
void makeNULL(Queue *q);

#endif