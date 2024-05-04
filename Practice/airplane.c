/*
    Airplane baggage problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct
{
    String id;
    String craftName;
    float maxCapacity;
} Info;

typedef struct
{
    String item;
    float weight;
} Baggage;

typedef struct bagSpot
{
    Baggage bag;
    struct bagSpot *nextbag;
}cargoSize, *cargoHold;

typedef struct
{
    Info details;
    cargoHold container;
    float currCapacity;
} Airplane;

// Functions
void storeBaggage(Airplane *TP, String id, Baggage bag);
cargoHold getHeavy(cargoHold *cont, float hlimit);
void display(Airplane thisplane);

int main()
{
    Baggage bag1 = {"BlueRec", 1.87};
    Baggage bag2 = {"BlueSqu", 2.00};
    Baggage bag3 = {"RedRec", 0.59};
    Baggage bag4 = {"RedSqu", 1.25};
    Baggage bag5 = {"PurpleRec", 0.37};

    Airplane PhiAir = {{"73657074", "Birtha", 50}, NULL, 0};

    storeBaggage(&PhiAir, "73657074", bag1);
    storeBaggage(&PhiAir, "73657074", bag2);
    storeBaggage(&PhiAir, "73657074", bag3);
    storeBaggage(&PhiAir, "73657074", bag4);
    storeBaggage(&PhiAir, "73657074", bag5);
    
    display(PhiAir);

    cargoHold heavyCargo;

    return 0;
}


void storeBaggage(Airplane *TP, String id, Baggage bag)
{
    if (!strcmp(TP->details.id, id) && (TP->currCapacity + bag.weight) <= TP->details.maxCapacity)
    {
        cargoHold newNode = malloc(sizeof(cargoSize));
        if (newNode != NULL)
        {
            newNode->bag = bag;
            newNode->nextbag = TP->container; // Link the new node to the existing cargo hold
            TP->container = newNode; // Update the cargo hold pointer
            TP->currCapacity += bag.weight;
        }
    }
}


cargoHold getHeavy(cargoHold *cont, float hlimit)
{
    // 
}

void display(Airplane thisplane)
{
    cargoHold trav = thisplane.container;
    while (trav != NULL)
    {
        printf("%s %.2f", trav->bag.item, trav->bag.weight);
        trav = trav->nextbag;
    }
    
}