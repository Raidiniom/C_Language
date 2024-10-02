#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

int main() {

    ProdDict Inventory;
    initDictionary(&Inventory, 15);

    Stack Hold;
    initStack(&Hold);

    pushITEM(&Hold, createProduct(0, "Button", 10, 9.99));
    pushITEM(&Hold, createProduct(1, "SCogWheel", 15, 15.99));
    pushITEM(&Hold, createProduct(2, "LCogWheel", 20, 20.99));
    pushITEM(&Hold, createProduct(3, "Press", 8, 109.99));
    pushITEM(&Hold, createProduct(4, "Mixer", 6, 80.99));
    pushITEM(&Hold, createProduct(5, "Couldron", 8, 49.99));
    pushITEM(&Hold, createProduct(6, "WWheel", 30, 59.99));
    pushITEM(&Hold, createProduct(7, "LWWheel", 50, 100.99));
    pushITEM(&Hold, createProduct(8, "Zinc", 100, 14.99));
    pushITEM(&Hold, createProduct(9, "Copper", 150, 14.99));
    pushITEM(&Hold, createProduct(10, "Bronze", 200, 19.99));
    pushITEM(&Hold, createProduct(11, "BlazeBurner", 14, 149.99));

    printf("Origin Stack: \n");
    displayStack(Hold);

    printf("%d\n", isDuplicate(Inventory, createProduct(11, "BlazeBurner", 14, 149.99)));

    // addITEM(&Inventory, peekSTACK(Hold));
    
    transferITEM(&Inventory, &Hold);

    // popITEM(&Hold);
    // popITEM(&Hold);
    // popITEM(&Hold);
    
    printf("\n\nStatus Stack: \n");
    displayStack(Hold);
    printf("\n\nDictionary!\n");
    printf("%d\n", isDuplicate(Inventory, createProduct(11, "BlazeBurner", 14, 149.99)));
    displayDictionary(Inventory);
    
    return 0;
}
