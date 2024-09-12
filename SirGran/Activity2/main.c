#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Sets.h"

int main() {
    Set set_A = create_set(10);
    Set set_B = create_set(10);
    Set universal = create_set(10);
    Set set_U;

    printf("Universal Set:\n");
    add_elem(&universal, 2);
    add_elem(&universal, 3);
    add_elem(&universal, 5);
    add_elem(&universal, 8);
    add_elem(&universal, 0);
    
    display_set(universal);
    printf("Cardinality -> %d\n", cardinality(universal));

    add_elem(&set_A,3);
    add_elem(&set_A,5);
    add_elem(&set_A,0);
    add_elem(&set_A,8);

    add_elem(&set_B,3);
    add_elem(&set_B,5);
    add_elem(&set_B,1);
    add_elem(&set_B,9);
    
    printf("Set A:\n");
    display_set(set_A); // is a subset of the universal
    printf("Cardinality -> %d\n", cardinality(set_A));
    printf("Set B:\n");
    display_set(set_B); // not a subset of the universal
    printf("Cardinality -> %d\n", cardinality(set_B));

    // printf("\nChecking Subset:\n");
    // printf("Is subset %s\n", (is_subset(universal, set_A)) ? "True": "False");
    // printf("Is subset %s\n", (is_subset(universal, set_B)) ? "True": "False");
    
    printf("Union Set:\n");
    set_U = union_set(set_A, set_B);
    display_set(set_U);

    return 0;
}

