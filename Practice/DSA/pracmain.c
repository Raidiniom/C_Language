#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom Headers
#include "pracque.h"
// #include "pracst.h"

int main() {
    NQueue circleQ;

    initNQueue(&circleQ);

    enqueue(&circleQ, createName("voltaire","rati"));
    enqueue(&circleQ, createName("clarence","dian"));
    enqueue(&circleQ, createName("yousif","ceba"));
    enqueue(&circleQ, createName("charles","boce"));
    enqueue(&circleQ, createName("john","gero"));
    enqueue(&circleQ, createName("ivan","jaym"));
    enqueue(&circleQ, createName("summi","dera"));
    enqueue(&circleQ, createName("kurt","aron"));
    enqueue(&circleQ, createName("cron","raym"));

    printf("\nInitial List:\n");
    displayFront(front(circleQ));
    displayQueue(circleQ);

    Name *filtered = filterNames(&circleQ, "ra");
    printf("\nFiltered Names\n");
    for (int i = 0; filtered[i].lname[0] != '\0'; i++)
    {
        printf("%s, %s\n", filtered[i].fname, filtered[i].lname);
    }
    

    return 0;
}