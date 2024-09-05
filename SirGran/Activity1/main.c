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

    Name *studList = getStudent(q, "BSIT", male);

    // makeNULL(&q);
    // visualizeQueue(q);
    
    for (int i = 0; !strcmp(studList[i].fname, "/0"); i++)
    {
        printf("%s, %s\n", studList[i].fname, studList[i].lname);
    }
    

    return 0;
}