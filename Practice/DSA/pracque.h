#ifndef PRACQ_H
#define PRACQ_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

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

        return true;
    }
    return false;
}
bool dequeue(NQueue *nq) {
    if (!isEmpty(*nq))
    {
        nq->elems[nq->front] = nq->elems[nq->front += 1];

        return true;
    }
    return false;
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
Name *filterNames(NQueue *nq, String filterString) {
    Name *returnName = malloc((MAX + 1) * sizeof(Name));

    int j = 0;

    for (int i = nq->rear; i != (nq->front + 1) % MAX; i = (i + 1) % MAX)
    {
        if (strcmp(nq->elems[i].lname, filterString) > 0)
        {
            
            strcpy(returnName[j].fname, nq->elems[i].fname);
            strcpy(returnName[j].lname, nq->elems[i].lname);    

            for (int x = i; x != (nq->rear + 1) % MAX; x++)
            {
                nq->elems[x] = nq->elems[(x + 1) % MAX];
            }

            nq->rear = (nq->rear - 1) % MAX;
            //  debugging
            // printf("F:%d R:%d\n", nq->front, nq->rear);
            j++;
        }
        
    }
    returnName[j].fname[0] = '\0';
    returnName[j].lname[0] = '\0';
    

    return returnName;
}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n) {
    if (!isFull(*nq))
    {
        if (isEmpty(*nq)) // here an if statement if this is the 1st insert
        {
            nq->rear = (nq->rear + 1) % MAX;
            nq->elems[nq->rear] = n;
        }
        else // in here is inserting and should move the elems to the right
        {
            int i;
            for (i = nq->rear; i != nq->front; i = (i - 1) % MAX)
            {
                if (strcmp(nq->elems[i].lname, n.lname) > 0)
                {
                    // inserts the data in the empty slot
                    nq->elems[(i + 1) % MAX] = nq->elems[i];
                }
                else
                {
                    break;
                }
            }

            nq->elems[(i + 1) % MAX] = n;
            nq->rear = (nq->rear + 1) % MAX;
            
        }
        return true;
    }
    return false;
}

#endif
