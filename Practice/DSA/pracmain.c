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
    enqueue(&circleQ, createName("wewew","hallo"));

    printf("\nInitial List:\n");
    displayFront(front(circleQ));
    displayQueue(circleQ);

    dequeue(&circleQ);
    dequeue(&circleQ);
    dequeue(&circleQ);

    printf("\nDeleted 3:\n");
    displayFront(front(circleQ));
    displayQueue(circleQ);

    return 0;
}