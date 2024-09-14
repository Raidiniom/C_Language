#ifndef SETS_H
#define SETS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
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
    return set.elems[index] == 1;
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
    
    for (int i = 0; i < size; i++)
    {
        if (set_a.elems[i] == 1 || set_b.elems[i] == 1)
        {
            set_U.elems[i] = 1;
            set_U.count++;
        }
        
    }
    

    return set_U;
}

Set intersection_set(Set set_a, Set set_b) {
    if (cardinality(set_a) != 0 && cardinality(set_b) != 0)
    { 
        int size = (set_a.max > set_b.max) ? set_a.max : set_b.max;
        Set set_I = create_set(size);

        for (int i = 0; i < size; i++)
        {
            if (set_a.elems[i] == 1 && set_b.elems[i] == 1)
            {
                set_I.elems[i] = 1;
                set_I.count++;
            }
            
        }
        

        return set_I;
    }
    
}

Set difference_set(Set set_a, Set set_b) {
    if (cardinality(set_a) != 0 && cardinality(set_b) != 0)
    {
        int size = (set_a.max > set_b.max) ? set_a.max : set_b.max;
        Set set_D = create_set(size);
        for (int i = 0; i < size; i++)
        {
            if (set_a.elems[i] == 1)
            {
                if (is_element(set_a, i) != is_element(set_b, i))
                {
                    set_D.elems[i] = 1;
                    set_D.count++;
                }
            }
            
        }
        

        return set_D;
    }
    
}

Set symetric_diff_set(Set set_a, Set set_b) {
    if (cardinality(set_a) != 0 && cardinality(set_b) != 0)
    {
        int size = (set_a.max > set_b.max) ? set_a.max : set_b.max;
        Set set_SD = create_set(size);

        for (int i = 0; i < size; i++)
        {
            if (set_a.elems[i] == 1 || set_b.elems[i] == 1)
            {
                if (!is_element(set_a, i) || !is_element(set_b, i))
                {
                    set_SD.elems[i] = 1;
                    set_SD.count++;
                }
            }
            
        }
        

        return set_SD;
    }
    
}

int cardinality(Set set) {
    return set.count;
}


#endif