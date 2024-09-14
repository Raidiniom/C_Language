#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[50];

typedef struct {
    String fname;
    String lname;
} Name;

typedef struct {
    Name owner;
    float weight;
} Luggage;

typedef struct node{
    Luggage bag;
    struct node *next;
} nodeSize, *cargoHold;

cargoHold populateList(cargoHold *list);
void insert(cargoHold *list, Luggage bag);
void search(cargoHold list, float weight);
void displayList(cargoHold list);

int main()
{
    cargoHold cebuAir;
    cebuAir = populateList(&cebuAir);

    displayList(cebuAir);

    printf("Searching for Heavy Luggage: \n");
    search(cebuAir, 2.00);

    return 0; 
}

cargoHold populateList(cargoHold *list)
{
    cargoHold hold = NULL;

    Luggage bag1 = {{"Ratilla", "Voltaire"}, 5.02};
    Luggage bag2 = {{"Gerozaga", "John"}, 2.3};
    Luggage bag3 = {{"Dianco", "Clarence"}, 4.25};
    Luggage bag4 = {{"Ceballos", "Yousif"}, 1.60};
    Luggage bag5 = {{"Bocaqosa", "Charles"}, 3.20};
    Luggage bag6 = {{"Derama", "Summi"}, 1.12};

    insert(&hold, bag1);
    insert(&hold, bag2);
    insert(&hold, bag3);
    insert(&hold, bag4);
    insert(&hold, bag5);
    insert(&hold, bag6);

    return hold;
}

void insert(cargoHold *list, Luggage bag)
{
    cargoHold newNode = malloc(sizeof(nodeSize));

    newNode->bag = bag;
    newNode->next = *list;

    *list = newNode;
}

void search(cargoHold list, float weight)
{
    cargoHold trav = list;
    while (trav != NULL)
    {
        if (trav->bag.weight >= weight)
        {
            printf("%s, %s | %.2f\n", trav->bag.owner.fname, trav->bag.owner.lname, trav->bag.weight);
            trav = trav->next;
        }
        else
        {
            trav = trav->next;
        }
        
    }
    
}

void displayList(cargoHold list)
{
    cargoHold trav = list;
    printf("Owner | Luggage Weight\n");
    while (trav != NULL)
    {
        printf("%s, %s | %.2f\n", trav->bag.owner.lname, trav->bag.owner.fname, trav->bag.weight);
        trav = trav->next;
    }
    
}