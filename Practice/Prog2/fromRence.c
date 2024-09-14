#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int item;
    struct node *link;
}NodeType, *NodePtr;

void insertFront(NodePtr *item, int object);
void display(NodePtr list);
void deleteFront(NodePtr *list);
void deleteRear(NodePtr *list);
void deleteItem(NodePtr *list,int item);
void deleteItemOccurance(NodePtr *list, int item);
void getAllFactors(NodePtr *list, int item, NodePtr *factorList);

int main(){
    NodePtr myList = NULL;

    display(myList);
    insertFront(&myList, 10);
    insertFront(&myList, 3);
    insertFront(&myList, 23);
    insertFront(&myList, 16);
    insertFront(&myList, 3);
    insertFront(&myList, 15);
    insertFront(&myList, 21);
    insertFront(&myList, 9);
    insertFront(&myList, 3);
    insertFront(&myList, 20);
    insertFront(&myList, 3);
    insertFront(&myList, 15);
    display(myList);

    deleteFront(&myList);
    display(myList);

    deleteRear(&myList);
    display(myList);

    deleteItem(&myList,20);
    display(myList);

    deleteItemOccurance(&myList, 3);
    display(myList);
    
   NodePtr factorList = NULL;
    getAllFactors(&myList, 3, &factorList);
    printf("Factors of 3: ");
    display(factorList);
    
    return 0;
}
void insertFront(NodePtr *myList, int object){
    NodePtr newNode = malloc(sizeof(NodeType));
    newNode->item = object;
    newNode->link = *myList;
    *myList = newNode;
}
void display(NodePtr myList){
    printf("{");
    while(myList != NULL){
        printf("%d", myList->item);
        if(myList->link != NULL){
            printf(", ");
        }
        myList = myList->link;
    }
    printf("}\n");
}
void deleteFront(NodePtr *list){
    if (*list != NULL){
        NodePtr temp = *list;
        *list = (*list)->link;
        free(temp);
    }
}
void deleteRear(NodePtr *list){
    if(*list != NULL){
        NodePtr temp, *trav;
        for(trav = list; (*trav)->link != NULL; trav = &(*trav)->link){}
        temp = *trav;
        *trav = NULL;
        free(temp);
    }
}
void deleteItem(NodePtr *list, int item){
    if(*list != NULL){
        NodePtr temp, *trav;
        for(trav = list; (*trav)->link != NULL && (*trav)->item != item; trav = &(*trav)->link){}
        temp = *trav;
            *trav = temp->link;
        free(temp);
    }
}
void deleteItemOccurance(NodePtr *list, int item) {
    NodePtr *trav = list;
    while (*trav!= NULL) {
        if ((*trav)->item == item) {
            NodePtr temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
}
void getAllFactors(NodePtr *list, int item, NodePtr *factorList){
    NodePtr trav = *list;
    while (trav!= NULL)
    {
        if (trav->item % item == 0)
        {
            insertFront(factorList, trav->item);
        }
        trav = trav->link;
        
    }
}