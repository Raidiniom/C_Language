#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.c"

int main()
{
    Node head = NULL;

    printf("----Start of Inserting---- \n");
    display_Link(head);

    for (int i = 0; i < 9; i++)
    {
        insert_Front(&head, i);
    }
    
    display_Link(head);

    insert_Rear(&head, 78);

    display_Link(head);

    insert_At(&head, 55, 6);

    display_Link(head);
    printf("----End of Inserting---- \n");

    printf("\n----Start of Deleting---- \n");
    delete_Front(&head);
    display_Link(head);

    delete_Rear(&head);
    display_Link(head);

    delete_At(&head, 6);
    display_Link(head);

    delete_Item(&head, 4);
    display_Link(head);

    printf("----End of Deleting---- \n");

    search_Item(head, 10);

    free(head);

    return 0;
}