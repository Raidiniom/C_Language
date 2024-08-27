#include <stdio.h>
#include <stdbool.h>
#include "stacks.h"
#include "student.h"

Stacks createStack() {
    Stacks new;

    new.count = 0;

    return new;
}

void initStack(Stacks *s) {
    s->count = 0;
}

bool isEmpty(Stacks s) {
    return s.count == 0;
}

bool isFull(Stacks s) {
    return s.count >= MAX;
}

void display(Stacks s) {
    printf("Student List: \nID  |  Name  |  Program\n");
    for (int i = 0; i < s.count; i++)
    {
        printf("%d  |  %s  |  %s \n", s.list[i].studID, s.list[i].studName, s.list[i].program);
    }
    printf("\n");
    
}


bool push(Stacks *s, Student elem) {
    if (!isFull(*s))
    {
        s->list[(s->count)++] = elem;
        return true;
    }
    return false;
}

bool pop(Stacks *s) {
    if (!isEmpty(*s))
    {
        (s->count)--;
        return true;
    }
    return false;
}

Student peek(Stacks s) {
    return s.list[s.count - 1];
}

// Stacks findEven(Stacks origin) {
//     Stacks hold = createStack();

//     int hold_item;

//     while (!isEmpty(origin))
//     {
//         hold_item = peek(origin);

//         if (hold_item % 2 == 0)
//         {
//             push(&hold, hold_item);
//         }
//         pop(&origin);
//     }
    
//     return hold;
// }

Stacks getStudent(Stacks origin, String program) {
    Stacks hold = createStack();
    int i = 0;

    while (!isEmpty(origin))
    {
        if (strcmp(origin.list[i].program, program) == 0)
        {
            push(&hold, origin.list[i]);
        }
        i++;
        pop(&origin);
    }
    
    return hold;
}

// void arrangeStudent(Stacks *origin) {
//     Student studList[(*origin).count];
//     Student temp;

//     for (int i = 0; i < (*origin).count; i++)
//     {
//         studList[i] = peek(*origin);
//         pop(origin);
//     }
    

//     while (!isEmpty(*origin))
//     {
//         for (int i = 0; i < (*origin).count-1; i++) {
//             for (int j = 0; j < (*origin).count-i-1; j++) {
//                 if (strcmp(studList[j].studName, studList[j+1].studName) > 0) {
//                     // Swap the students
//                     temp = studList[j];
//                     studList[j] = studList[j+1];
//                     studList[j+1] = temp;
//                 }
//             }
//         }
//     }
    
//     for (int i = 0; i < (*origin).count; i++)
//     {
//         push(origin, studList[i]);
//     }
    
// }