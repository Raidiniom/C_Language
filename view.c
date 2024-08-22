#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.c"

int main()
{
    Node head = NULL;

    display_Link(head);

    for (int i = 0; i < 9; i++)
    {
        insert_Front(&head, 10 + i);
    }
    
    display_Link(head);

    insert_Rear(&head, 78);

    display_Link(head);

    insert_At(&head, 55, 5);

    display_Link(head);

    return 0;
}