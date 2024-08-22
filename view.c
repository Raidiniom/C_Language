#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.c"

int main()
{
    Node head = create_Node();

    display_Link(head);

    insert_Front(&head, 11);
    insert_Front(&head, 12);
    insert_Front(&head, 13);
    insert_Front(&head, 14);
    insert_Front(&head, 15);

    display_Link(head);

    return 0;
}