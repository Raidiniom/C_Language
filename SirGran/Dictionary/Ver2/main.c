#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stacktodictionary.h"

int main() {
    // Create the products
    Product p1 = create_product(1, "SCog", 64, 21.18);
    Product p2 = create_product(2, "LCog", 32, 26.29);
    Product p3 = create_product(3, "Alloy", 320, 10.59);
    Product p4 = create_product(4, "Basin", 10, 52.95);
    Product p5 = create_product(5, "Press", 5, 35.00);
    Product p6 = create_product(6, "Bronze", 128, 30.59);
    Product p7 = create_product(7, "Copper", 150, 10.00);
    Product p8 = create_product(8, "BlazeBerner", 8, 1040.99);
    Product p9 = create_product(9, "Pipe", 200, 102.99);
    Product p10 = create_product(10, "Pump", 4, 125.99);
    Product p11 = create_product(11, "SWaterWheel", 15, 500.99);
    Product p12 = create_product(12, "LWaterWheel", 20, 1000.99);
    Product p13 = create_product(13, "Drill", 44, 35.59);
    Product p14 = create_product(14, "AndeCase", 126, 25.99);

    // Create the stack
    Stack delivery;

    init_stack(&delivery);

    // Create the dictionary
    Dictionary warehouse;

    init_dictionary(&warehouse, 20);

    // It will display the 6 created items
    // display_product(p1);
    // display_product(p2);
    // display_product(p3);
    // display_product(p4);
    // display_product(p5);
    // display_product(p6);

    // push the items into the delivery stack
    push_item(&delivery, p1);
    push_item(&delivery, p8);
    push_item(&delivery, p2);
    push_item(&delivery, p5);
    push_item(&delivery, p6);
    push_item(&delivery, p4);
    push_item(&delivery, p7);
    push_item(&delivery, p3);
    push_item(&delivery, p9);
    push_item(&delivery, p10);
    push_item(&delivery, p11);
    push_item(&delivery, p12);
    push_item(&delivery, p13);
    push_item(&delivery, p14);


    // test the pop function
    // pop_item(&delivery);
    // pop_item(&delivery);
    // pop_item(&delivery);
    // pop_item(&delivery);
    // the function works

    // display the delivery stack if the item pushing works
    printf("Delivery Stack:\n");
    display_stack(delivery);

    debug_dictionary(warehouse);

    // test adding items to the dictionary
    for (int i = 0; i < 14; i++)
    {
        add_item(&warehouse, &delivery);
    }
    // add_item(&warehouse, &delivery);
    // add_item(&warehouse, &delivery);
    
    printf("Transferring Items from the delivery stack:\n");
    display_dictionary(warehouse);

    remove_item(&warehouse, 3, "Alloy");
    remove_item(&warehouse, 7, "Copper");

    printf("After removing an Item:\n");
    display_dictionary(warehouse);

    // printf("Debug Land:\n");
    // debug_get_hash(delivery);

    Product p2dup = create_product(2, "LCog", 100, 26.29);
    Product p3dup = create_product(1, "SCog", 100, 21.18);

    push_item(&delivery, p2dup);
    push_item(&delivery, p3dup);

    add_item(&warehouse, &delivery);

    printf("Adding Item that is a duplicate:\n");
    display_dictionary(warehouse);

    return 0;
}