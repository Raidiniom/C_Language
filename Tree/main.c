#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

int main() {
    NodePtr mytree;
    init_tree(&mytree);

    for (int i = 1; i <= 20; i++)
    {
        insert_data(&mytree, i);
    }
    

    in_order(mytree);
    printf("\n\n");
    // pre_order(mytree);
    // printf("\n\n");
    // post_order(mytree);

    return 0;
}