#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stacks.c"
#include "student.c"

int main() {
    Stacks USC = createStack();
    Stacks ITroom = createStack();

    Student stud1 = createStud(1, "Rence", "BSIT");
    Student stud2 = createStud(2, "Sep", "BSCS");
    Student stud3 = createStud(3, "Marq", "BSIS");
    Student stud4 = createStud(4, "Charles", "BSMED");

    push(&USC, stud1);
    push(&USC, stud2);
    push(&USC, stud3);
    push(&USC, stud4);
    display(USC);

    ITroom = getStudent(USC, "BSIT");
    display(ITroom);

    arrangeStudent(&USC);
    display(USC);

    return 0;
}