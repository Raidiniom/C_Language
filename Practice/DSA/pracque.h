#ifndef PRACQ_H
#define PRACQ_H

#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef char String[30];

typedef struct {
    String fname;
    String lname;
} Name;

typedef struct {
    Name elems[MAX];
    int front;
    int rear;
} NQueue;

Name createName(String fname, String lname) {
    Name start;

    strcpy(start.fname, fname);
    strcpy(start.lname, lname);

    return start;
}

void initNQueue(NQueue *nq) {
    nq->front = 0;
    nq->rear = -1;
}
bool isEmpty(NQueue nq) {
    return (nq.front == (nq.rear + 1) % MAX);
}
bool isFull(NQueue nq) {
    return ((nq.rear + 2) % MAX == nq.front);
}
void displayQueue(NQueue nq) {
    
    for (int i = nq.front; i != (nq.rear + 1) % MAX; i = (i + 1) % MAX)
    {
        printf("%s, %s\n", nq.elems[i].fname, nq.elems[i].lname);
    }
        
}

bool enqueue(NQueue *nq, Name n){
    if (!isFull(*nq))
    {
        nq->rear = (nq->rear + 1) % MAX;
        nq->elems[nq->rear] = n;

        // Uncomment for debugging
        // printf("F:%d R:%d", nq->front, nq->rear);
    }
    
}
bool dequeue(NQueue *nq) {
    if (!isEmpty(*nq))
    {
        nq->elems[nq->front] = nq->elems[nq->front += 1];
    }
    
}
Name front(NQueue nq) {
    Name pop;

    pop = nq.elems[nq.front];

    return pop;
}

void displayFront(Name pop) {
    printf("%s, %s is in front of the queue\n", pop.fname, pop.lname);
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString);

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n);

#endif