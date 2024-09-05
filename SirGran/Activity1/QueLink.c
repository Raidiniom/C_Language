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

void debugQueue(Queue q) {
    NodePTR trav = q.head;

    printf("Student List: \n");
    while (trav != NULL)
    {
        printf("%d %s, %s %s %s\n", trav->Elem.Stud_id, trav->Elem.Stud_name.fname, trav->Elem.Stud_name.lname, (trav->Elem.Stud_sex == 0) ? "Female" : "Male", trav->Elem.Stud_program);
        trav = trav->next;
    }
    
}

void visualizeQueue(Queue q) {
    if (!isEmpty(q))
    {
        Data comp = q.head->Elem;

        while (!isEmpty(q))
        {   
            printf("%d %s\n", front(q).Stud_id, front(q).Stud_name.fname);
            // Using enQueue and deQueue
            // enQueue(&q, front(q));
            // deQueue(&q);

            // this is basically Trav
            q.head = q.head->next;


            // if (comp.Stud_id == front(q).Stud_id)
            // {
            //     break;
            // }
            
        }
    }
    else
    {
        printf("Queue is Empty!\n");
    }
    
}

bool enQueue(Queue *q, Data d) {
    NodePTR newNode = malloc(sizeof(NodeType));
    newNode->Elem = d;
    newNode->next = NULL;

    if (isEmpty(*q))
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }
    
    
}

bool deQueue(Queue *q) {
    NodePTR temp;

    if (!isEmpty(*q))
    {
        temp = q->head->next;
        free(q->head);
        q->head = temp;

        return true;
    }
    return false;
}

Data front(Queue q) {
    return q.head->Elem;
}

void makeNULL(Queue *q) {
    NodePTR freethis;

    if (!isEmpty(*q))
    {
        while (q->head != NULL)
        {
            freethis = q->head;
            q->head = q->head->next;
            free(freethis);
        }
        
    }
    
}