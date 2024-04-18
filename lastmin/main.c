#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cargoship.h"

int main()
{
    Ship irina;

    String shipname;
    int capacity, pick;

    printf("Enter Ship's Cargo Weight Capacity: ");
    scanf("%d", &capacity);

    printf("Enter Ship's Name: ");
    scanf("%s", shipname);

    irina = createShip(capacity, shipname);

    addCargo(&irina, createProduct("Mouse", "Logitech", 'T', createDate(1, 2052), 5));

    viewCargo(irina);

    /*
    - Remove a Product
    - Search Product by type / weight / manufacturer
    - Sort storage by type / weight
    - The products should not go over the carry capacity of the cargo ship
    */


    return 0;
}
