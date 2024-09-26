#include <stdio.h>
#include <stdlib.h>

#include "stacklink.h"

int main() {
    ProdDict testpd;
    initProdDict(&testpd, 20);

    addITEM(&testpd, createProd(10, "Toothpaste", 50, 10));
    addITEM(&testpd, createProd(11, "Shampoo", 30, 20));
    addITEM(&testpd, createProd(12, "Soap", 100, 5));
    addITEM(&testpd, createProd(13, "Toilet Paper", 200, 15));
    addITEM(&testpd, createProd(14, "Hand Sanit", 150, 8));
    addITEM(&testpd, createProd(15, "Tampons", 100, 25));
    addITEM(&testpd, createProd(16, "Deodorant", 75, 12));
    addITEM(&testpd, createProd(4, "Ear Plugs", 30, 100.59));
    addITEM(&testpd, createProd(3, "Router", 25, 250.5));
    addITEM(&testpd, createProd(2, "Monitor", 20, 199.9));
    addITEM(&testpd, createProd(0, "Mouse", 10, 15.9));

    // Initial Dictionary
    displayDictionary(testpd);

    printf("================================================================================\n");

    removeITEM(&testpd, 12, "Soap");
    removeITEM(&testpd, 0, "Mouse");

    // Deleted Some in the Dictionary
    displayDictionary(testpd);

    printf("================================================================================\n");

    displayProduct(retrieveITEM(testpd, 13, "Toilet Pap"));

    return 0;
}