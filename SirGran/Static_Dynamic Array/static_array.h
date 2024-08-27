#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#define MAX 50

typedef struct {
    int count;
    int list[MAX];
} array;

array init_array();

void insert_front(array *list, int data);
void insert_rear(array *list, int data);
void insert_at(array *list, int data, int position);

void delete_front(array *list);
void delete_rear(array *list);
void delete_at(array *list, int position);
void delete_item(array *list, int item);

void display_array(array list);

#endif
