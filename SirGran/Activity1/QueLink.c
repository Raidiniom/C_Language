#include <stdio.h>
#include <stdlib.h>

#include "QueLink.h"

Queue createQueue() {
    Queue initQ;

    initQ.head = NULL;
    initQ.tail = NULL;

    return initQ;
}

bool isEmpty(Queue q) {
    return q.head == NULL;
}

void displayQueue(Queue q) {
    NodePTR trav = q.head;

    printf("Student List: \n");
    while (trav != NULL)
    {
        printf("%d\t%s, %s\t%s\t%s\n", trav->Elem.Stud_id, trav->Elem.Stud_name.fname, trav->Elem.Stud_name.lname, (trav->Elem.Stud_sex == 0) ? "Female" : "Male", trav->Elem.Stud_program);
        trav = trav->next;
    }
    
}

bool enQueue(Queue *q, Data d) {
    // 
}

bool deQueue(Queue *q) {
    // 
}

Data front(Queue q);
void makeNULL(Queue *q);