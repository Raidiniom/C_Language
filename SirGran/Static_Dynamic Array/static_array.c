#include <stdio.h>
#include <stdlib.h>
#include "static_array.h"

array init_array() {
    array create_array;

    create_array.count = 0;

    return create_array;
}

void insert_front(array *list, int data) {
    if (list->count == 0)
    {
        list->list[0] = data;
    }
    
    if (list->count != MAX)
    {
        for (int i = list->count; i > 0; i--)
        {
            list->list[i] = list->list[i - 1];
        }
        
        list->list[0] = data;
        list->count++;
    }
    
}

// Also known as Push in Stacks
void insert_rear(array *list, int data) {
    if (list->count != MAX)
    {
        int i = 0;
        while (i < list->count)
        {
            i += 1;
        }
        list->list[i] = data;
        list->count++;
    }
    
}

void insert_at(array *list, int data, int position) {
    if (list->count != MAX && position >= 0 && position <= list->count) {
        for (int i = list->count; i > position; i--) {
            list->list[i] = list->list[i - 1];
        }

        list->list[position] = data;
        list->count++;

    }
}


void delete_front(array *list) {
    if (list->count > 0) {
        
        for (int i = 0; i < list->count - 1; i++) {
            list->list[i] = list->list[i + 1];
        }
        
        list->count--;
    }
}

// Also known as Pop in Stacks
void delete_rear(array *list) {
    if (list->count > 0) {
        
        list->count--;
    }
}

void delete_at(array *list, int position) {
    if (position >= 0 && position < list->count) {
        
        for (int i = position - 1; i < list->count - 1; i++) {
            list->list[i] = list->list[i + 1];
        }
        
        list->count--;
    }
}

void delete_item(array *list, int item) {
    int position = 0;
    
    for (int i = 0; i < list->count; i++) {
        position = i;
        if (list->list[i] == item) {
            delete_at(list, position);
            break;
        }
        
    }

}


void display_array(array list) {
    printf("[");
    for (int i = 0; i < list.count; i++)
    {
        printf("%d", list.list[i]);
        if (i < list.count - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Current Count: %d\n", list.count);
}