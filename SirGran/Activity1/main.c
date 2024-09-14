#include <stdio.h>
#include <stdlib.h>

#include "QueLink.c"
#include "student.c"

int main() {
    Queue q = createQueue();

    Student stud1 = createStudent(111, createName("Volt", "Rat"), male, "BSIT");
    Student stud2 = createStudent(222, createName("Clar", "Dia"), male, "BSIT");
    Student stud3 = createStudent(333, createName("Summ", "Der"), female, "BSIS");
    Student stud4 = createStudent(444, createName("Maya", "Ty"), female, "BSIS");
    Student stud5 = createStudent(555, createName("Yous", "Ceb"), male, "BSCS");
    Student stud6 = createStudent(666, createName("Aly", "Jo"), female, "BSCS");

    enQueue(&q, stud1);
    enQueue(&q, stud2);
    enQueue(&q, stud3);
    enQueue(&q, stud4);
    enQueue(&q, stud5);
    enQueue(&q, stud6);

    // debugQueue(q);

    visualizeQueue(q);

    printf("\n++++****++++****++++****++++\n");

    Name *studList = getStudent(q, "BSIT", male);

    // makeNULL(&q);
    // visualizeQueue(q);
    
    for (int i = 0; strcmp(studList[i].fname, "") != 0; i++)
    {
        printf("%s, %s\n", studList[i].fname, studList[i].lname);
    }
    
    free(studList);

    printf("\n++++****++++****++++****++++\n");
    Queue sortedQueue = createQueue();

    Student stud10 = createStudent(999, createName("Elysia", "HOHE"), female, "BSCS");
    Student stud11 = createStudent(1010, createName("Kaplas", "Destruction"), male, "BSCS");
    Student stud12 = createStudent(1111, createName("Eimi", "Notoka"), female, "BSIT");
    Student stud13 = createStudent(1212, createName("Kebin", "Delivery"), male, "BSIS");
    Student stud14 = createStudent(1313, createName("Nonomi", "Koroka"), female, "BSCPE");
    insertSorted(&sortedQueue, stud10);
    insertSorted(&sortedQueue, stud13);
    insertSorted(&sortedQueue, stud11);
    insertSorted(&sortedQueue, stud14);
    insertSorted(&sortedQueue, stud12);
    insertSorted(&sortedQueue, stud1);
    insertSorted(&sortedQueue, stud3);
    insertSorted(&sortedQueue, stud4);
    insertSorted(&sortedQueue, stud6);
    insertSorted(&sortedQueue, stud5);

    visualizeQueue(sortedQueue);

    return 0;
}