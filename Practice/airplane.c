/*
    Airplane baggage problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[50];

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
cargoHold getHeavy(cargoHold *cont);
void display(Airplane thisplane);

int main()
{
    Baggage bag1 = {"BlueRec", 1.87};
    Baggage bag2 = {"BlueSqu", 2.00};
    Baggage bag3 = {"RedRec", 0.59};
    Baggage bag4 = {"RedSqu", 1.25};
    Baggage bag5 = {"PurpleRec", 0.37};

    Airplane PhiAir = {{"73657074", "Birtha", 50}, NULL, 0};

    cargoHold heavyCargo;

    return 0;
}


void storeBaggage(Airplane *TP, String id, Baggage bag)
{
    if (!strcmp(TP->details.id, id))
    {
        /* code */
    }
    
}

cargoHold getHeavy(cargoHold *cont)
{
    // 
}

void display(Airplane thisplane)
{
    // 
}