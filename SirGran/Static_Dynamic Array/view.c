#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.c"
#include "static_array.c"

void dynamic_array();
void static_array();

int main()
{
    printf("\n\nDynamic Array\n");
    dynamic_array();

    // printf("\n\nStatic Array\n");
    // static_array();

    return 0;
}

void dynamic_array() {
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
}

void static_array() {
    array start = init_array();

    printf("Inserting Data: \n");
    display_array(start);

    for (int i = 0; i < 5; i++)
    {
        insert_front(&start, i);
    }
    display_array(start);
    
    // insert_rear(&start, 6);
    // display_array(start);
    // insert_rear(&start, 7);
    // display_array(start);
    // insert_at(&start, 50, 5);
    // display_array(start);
    // insert_front(&start, 80);
    // display_array(start);

    printf("\nDeleting Data: \n");
    delete_front(&start);
    display_array(start);
    delete_rear(&start);
    display_array(start);
    delete_at(&start, 3);
    display_array(start);
    delete_item(&start, 50);
    display_array(start);
}