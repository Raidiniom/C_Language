#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

void insertRear(NodePtr *list, int num);
// void deleteNum(NodePtr *list, int delnum);
// int searchNum(NodePtr list, int sernum);
void findFactor(NodePtr list, NodePtr *factor, int base);
void display(NodePtr list);

int main()
{
    NodePtr myList = NULL;
    NodePtr factor = NULL;

    printf("Start\n");
    display(myList);

    int arr[] = {1, 2, 3, 10, 20, 30, 12, 6, 8, 9, 24, 18};

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); ++i) {
        insertRear(&myList, arr[i]);
    }

    printf("Populated\n");
    display(myList);

    findFactor(myList, &factor, 2);

    printf("Factors\n");
    display(factor);

    return 0;
}

void insertRear(NodePtr *list, int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    NodePtr trav = *list;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    
    

    trav->next = newNode;
}

// void deleteNum(NodePtr *list, int delnum)
// {
//     NodePtr temp, *trav;

//     trav = list;
//     while ((*trav)->next != NULL && (*trav)->num != delnum)
//     {
//         trav = &(*trav)->next;
//     }
    
//     temp = *trav;
//     *trav = temp->next;
//     free(temp);
// }

// int searchNum(NodePtr list, int sernum)
// {
//     while (list != NULL)
//     {
//         if (list->num % sernum == 0)
//         {
//             return list->num;
//         }
//         list = list->next;
//     }
//     return 0;
// }

void findFactor(NodePtr list, NodePtr *factor, int base)
{
    /*if the data from the list can be divided by the base with no remainder 
        , then append that data to the factor link-list*/

    while (list != NULL)
    {
        if (list->num % base == 0)
        {
            insertRear(factor, list->num);
            // deleteNum(&list, searchNum(list, base));
        }
        list = list->next;
    }
}

void display(NodePtr list)
{
    printf("{");
    while (list != NULL)
    {
        printf("%d", list->num);
        list = list->next;
        if (list != NULL)
        {
            printf(", ");
        }
    }
    printf("}\n\n");
}