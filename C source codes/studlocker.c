#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 10

typedef struct{
    char studID[9];
    char studName[65];
    char course[5];
}Student;

typedef struct{
    char itemName[33];
    float weight;        /* Weight of the item to be stored */
}ItemDets;

typedef struct ItemNode{
    ItemDets item;
    struct ItemNode* nextItem;
}ItemNode, *ItemList;

typedef struct{
    Student owner;            /* Details of the student who owns the locker */
    ItemList IL;            /* Linked list representation of all the items inside a certain locker */
    int lockerStat;          /* 0 if locker is Vacant, 1 if occupied */
    float totWeight;        /* Total weight of all items in the locker */
}Locker;

void depositItem(Locker* L, char studID[], ItemDets newItem)
{
    if(!strcmp(L->owner.studID, studID) && (L->totWeight + newItem.weight) <= WEIGHTLIMIT)
    {
        ItemList newNode = malloc(sizeof(ItemNode));
        if (newNode != NULL)
        {
            newNode->item = newItem;
            ItemList *trav;
            for (trav = &(L->IL); *trav != NULL && (*trav)->item.weight < newItem.weight; trav = &(*trav)->nextItem) {}
            newNode->nextItem = *trav;
            *trav = newNode;
            L->totWeight += newItem.weight;
        }
        
    }
}

ItemList getHeavyItems(Locker* L, float limit)
{
    ItemList heavyList = NULL;
    ItemList prev = NULL;
    ItemList trav = L->IL;

    while (trav != NULL)
    {
        if (trav->item.weight > limit)
        {
            if (prev == NULL)
            {
                L->IL = trav->nextItem;
            }
            else
            {
                prev->nextItem = trav->nextItem;
            }
            
            trav->nextItem = heavyList;
            heavyList = trav;

            trav = prev->nextItem;
        }
        else
        {
            prev = trav;
            trav = trav->nextItem;
        }
        
    }

    // Without Prev
    // ItemList temp;
    // ItemList heavyList = NULL;
    // ItemList *current;
   
    // for(current = &(L->IL); *current != NULL;){
    //      if((*current)->item.weight > limit){
    //         temp = (*current)->nextItem;
    //         (*current)->nextItem = heavyList;
    //         heavyList = *current;
    //         *current = temp;
    //     } else {
    //         current = &(*current)->nextItem;
    //     }
    // }
    
    return heavyList;
}

void displayItemList(ItemList L)
{
    ItemList trav;
    float totWeight = 0;
    for(trav = L; trav != NULL; trav = trav->nextItem){
        totWeight += trav->item.weight;
        printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);

    }
    printf("\nTotal Weight: %.2fkg\n\n", totWeight);
}

int main(void)
{
    ItemDets item1 = {"Prog 1 Book", 0.35};
    ItemDets item2 = {"Shoes", 0.87};
    ItemDets item3 = {"Laptop", 2.35};  
    ItemDets item4 = {"Keyboard", 1.17};
    ItemDets item5 = {"Philo 1 Book", 3.50};

    Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
    ItemList heavyItems;

    depositItem(&myLocker, "14101941", item4);
    depositItem(&myLocker, "14101941", item2);
    depositItem(&myLocker, "14101941", item3);
    depositItem(&myLocker, "14101941", item1);
    depositItem(&myLocker, "14101941", item5);
    displayItemList(myLocker.IL);

    heavyItems = getHeavyItems(&myLocker, 1.00);
    displayItemList(myLocker.IL);
    displayItemList(heavyItems);
    return 0;
}
