#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "pracst.h"

int main() {
    Stack mystack;

    initStack(&mystack);

    Person p1 = createPerson("Voltaire", "Rati", 21, 'm');
    Person p2 = createPerson("Charles", "Boqe", 20, 'm');
    Person p3 = createPerson("Summi", "Dera", 19, 'f');
    Person p4 = createPerson("Alyssa", "Jo", 19, 'f');
    Person p5 = createPerson("Chelsea", "Colla", 21, 'f');
    Person p6 = createPerson("Rence", "Aber", 20, 'm');

    push(&mystack, p2);
    push(&mystack, p6);
    push(&mystack, p1);
    push(&mystack, p3);
    push(&mystack, p4);
    push(&mystack, p5);

    printf("Inserted\n");
    displayStack(mystack);

    insertSorted1(&mystack, createPerson("Clar", "Dian", 19, 'm'));

    printf("Insert Sorted\n");
    displayStack(mystack);

    return 0;
}

