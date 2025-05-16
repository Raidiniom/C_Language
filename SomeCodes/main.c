#include <stdio.h>
#include <stdlib.h>
#include "learner.h"

int main()
{
//    menu();
    TaskList sem2nd = createList(5);

    addTask(&sem2nd, createTask(createDate(1, 5, 2024), createDate(4, 5, 2024), createName("Gran", "Sabandal"), "Activity # 4", 50));
    addTask(&sem2nd, createTask(createDate(10, 6, 2024), createDate(14, 6, 2024), createName("Patrick", "Rero"), "Activity # 7", 25));
    addTask(&sem2nd, createTask(createDate(12, 7, 2024), createDate(24, 7, 2024), createName("John", "Belarmino"), "Relationship Entity Models", 40));
    addTask(&sem2nd, createTask(createDate(7, 8, 2024), createDate(10, 8, 2024), createName("GodWin", "Monstrate"), "VLSM with Static Routing", 100));
    addTask(&sem2nd, createTask(createDate(9, 9, 2024), createDate(31, 9, 2024), createName("Nanay", "Accting"), "Journal - Trial Balance", 60));

    display(sem2nd);

    printf("\n------------------------------------------------------------------\n");

    done(&sem2nd, 1, 5, 2024);
    done(&sem2nd, 12, 7, 2024);

    display(sem2nd);

    return 0;
}
