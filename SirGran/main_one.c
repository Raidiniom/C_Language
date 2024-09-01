#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queueadt.c"

int main() {
    Student stud1 = createStudent(1, createName("Volt", "Rat"), true, "BSIT", 2);
    Student stud2 = createStudent(2, createName("Clar", "Dia"), true, "BSIT", 2);
    Student stud3 = createStudent(3, createName("Char", "Baq"), true, "BSIT", 2);
    Student stud4 = createStudent(4, createName("Yous", "Ceb"), true, "BSIT", 2);
    Student stud5 = createStudent(5, createName("Miki", "Ard"), false, "BSIS", 2);
    Student stud6 = createStudent(6, createName("Fati", "San"), false, "BSIS", 2);
    Student stud7 = createStudent(5, createName("Vade", "May"), false, "BSIS", 2);
    Student stud8 = createStudent(6, createName("Jacq", "Jui"), false, "BSIS", 2);

    QueueADT myQueue = createQueue(10);

    enQue(&myQueue, stud1);
    enQue(&myQueue, stud2);
    enQue(&myQueue, stud3);
    enQue(&myQueue, stud4);
    enQue(&myQueue, stud5);
    enQue(&myQueue, stud6);
    enQue(&myQueue, stud7);
    enQue(&myQueue, stud8);

    printf("EnQueue: \n");
    // displayT(myQueue);
    
    // deQue(&myQueue);
    // deQue(&myQueue);
    
    // printf("DeQueue: \n");
    // displayT(myQueue);

    displayNT(myQueue);


    return 0;
}