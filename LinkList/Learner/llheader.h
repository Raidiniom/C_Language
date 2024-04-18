#ifndef LLHEADER_H_INCLUDED
#define LLHEADER_H_INCLUDED

typedef struct node{
    int data;
    struct node *next;
} Node;

void initLink(Node **link, int data)
{
    Node* head = malloc(sizeof(Node));

    head->data = data;
    head->next = NULL;
}

#endif
