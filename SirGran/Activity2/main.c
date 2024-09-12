#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    int *elems;
    int count;
    int max;
} Set;

Set create_set(int max);

bool add_elem(Set *set, int item);
bool remove_elem(Set *set, int item);

void display_set(Set set);

bool is_element(Set set, int item);
bool is_subset(Set set_a, Set set_b);

Set union_set(Set set_a, Set set_b);
Set intersection_set(Set set_a, Set set_b);
Set difference_set(Set set_a, Set set_b);
Set symetric_diff_set(Set set_a, Set set_b);

int cardinality(Set set);

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

Set create_set(int max) {
    Set initial_set;

    initial_set.count = 0;
    initial_set.max = max;
    initial_set.elems = calloc(max, sizeof(int));

    return initial_set;
}

bool add_elem(Set *set, int index) {
    if (cardinality(*set) != set->max)
    {
        if (set->elems[index] != 1)
        {
            set->elems[index] = 1;
            set->count++;

            return true;
        }
        
    }
    return false;
}
bool remove_elem(Set *set, int index) {
    if (cardinality(*set) != set->max)
    {
        if (set->elems[index] != 0)
        {
            set->elems[index] = 0;
            set->count--;

            return true;
        }
        
    }
    return false;
}

void display_set(Set set) {
    printf("Set -> {");
    for (int i = 0; i < set.max; i++)
    {
        printf("%d", set.elems[i]);
        if (i < set.max - 1)
        {
            printf(", ");
        }
        
    }
    printf("}\n");
}

bool is_element(Set set, int index) {
    if (cardinality(set) != 0 && set.elems[index] == 1)
    {
        return true;
    }
    return false;
}

bool is_subset(Set universal, Set subset) {
    if (cardinality(universal) != 0 && cardinality(subset) != 0)
    {
        int size = (universal.max > subset.max) ? universal.max : subset.max;
        for (int i = 0; i < size; i++)
        {
            if (subset.elems[i] == 1)
            {
                if (subset.elems[i] != universal.elems[i])
                {
                    return false;
                    break;
                }   
            }
        }
        return true;
    }
}

Set union_set(Set set_a, Set set_b) {
    int size = (set_a.max > set_b.max) ? set_a.max : set_b.max;
    Set set_U = create_set(size);
    
    for (int i = 0; i < set_U.max; i++)
    {
        if (set_a.elems[i] == 1 || set_b.elems[i] == 1)
        {
            set_U.elems[i] = 1;
        }
        
    }
    

    return set_U;
}
Set intersection_set(Set set_a, Set set_b);
Set difference_set(Set set_a, Set set_b);
Set symetric_diff_set(Set set_a, Set set_b);

int cardinality(Set set) {
    return set.count;
}