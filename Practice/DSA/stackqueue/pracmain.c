
// Custom Headers
#include "pracque.h"


int main() {
    NQueue circleQ;

    initNQueue(&circleQ);

    insertSorted(&circleQ, createName("voltaire","rati"));
    insertSorted(&circleQ, createName("clarence","dian"));
    insertSorted(&circleQ, createName("yousif","ceba"));
    insertSorted(&circleQ, createName("charles","boce"));
    insertSorted(&circleQ, createName("john","gero"));
    insertSorted(&circleQ, createName("ivan","jaym"));
    insertSorted(&circleQ, createName("summi","dera"));
    insertSorted(&circleQ, createName("kurt","aron"));
    insertSorted(&circleQ, createName("cron","raym"));

    printf("\nInitial List:\n");
    displayFront(front(circleQ));
    displayQueue(circleQ);

    // dequeue(&circleQ);
    // dequeue(&circleQ);
    // dequeue(&circleQ);
    // dequeue(&circleQ);

    // displayFront(front(circleQ));
    // displayQueue(circleQ);

    Name *filtered = filterNames(&circleQ, "ra");
    printf("\nFiltered Names\n");
    for (int i = 0; filtered[i].lname[0] != '\0'; i++)
    {
        printf("%s, %s\n", filtered[i].fname, filtered[i].lname);
    }

    printf("\ndebuging\n");
    displayQueue(circleQ);
    

    return 0;
}