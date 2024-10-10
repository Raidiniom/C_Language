#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

int main() {
    NodePtr mytree, mytreev2;
    init_tree(&mytree);
    init_tree(&mytreev2);

    for (int i = 1; i <= 20; i++)
    {
        insert_data(&mytree, i);
    }
    
    for (int i = 1; i <= 20; i++)
    {
        insert_data_v2(&mytreev2, i);
    }

    printf("V1 insert \n");
    in_order(mytree);
    printf("\n\n");
    printf("V2 insert \n");
    in_order(mytree);
    printf("\n\n");
    // pre_order(mytree);
    // printf("\n\n");
    // post_order(mytree);

    return 0;
}