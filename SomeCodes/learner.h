#ifndef LEARNER_H_INCLUDED
#define LEARNER_H_INCLUDED

#include <string.h>
#include <stdlib.h>

typedef char String[50];

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    String fname;
    String lname;
} Name;

typedef struct {
    Date given;
    Date deadline;
    Name teacher;
    String activity;
    int score;
} Task;

typedef struct {
    Task *details;
    int counted;
    int maxed;
} TaskList;

Date createDate(int day, int month, int year)
{
    Date init;

    init.day = day;
    init.month = month;
    init.year = year;

    return init;
}

Name createName(String fname, String lname)
{
    Name init;

    strcpy(init.fname, fname);
    strcpy(init.lname, lname);

    return init;
}

Task createTask(Date give, Date dead, Name teacher, String act, int score)
{
    Task init;

    init.given = give;
    init.deadline = dead;
    init.teacher = teacher;
    strcpy(init.activity, act);
    init.score = score;

    return init;
}

TaskList createList(int maxxer)
{
    TaskList init;

    init.counted = 0;
    init.maxed = maxxer;
    init.details = malloc(sizeof(Task) * maxxer);

    return init;
}

void display(TaskList view)
{
    for(int o = 0; o < view.counted; ++o)
    {
        printf("Activity Title: %s \n", view.details[o].activity);
        printf("Date Given: %d %d %d \n", view.details[o].given.day, view.details[o].given.month, view.details[o].given.year);
        printf("Deadline: %d %d %d \n", view.details[o].deadline.day, view.details[o].deadline.month, view.details[o].deadline.year);
        printf("Submit to: %s, %s \n", view.details[o].teacher.lname, view.details[o].teacher.fname);
        printf("Total Score: %d \n\n", view.details[o].score);
    }
}

void addTask(TaskList *listing, Task detail)
{
    if(listing->counted < listing->maxed)
    {
        listing->details[(listing->counted)++] = detail;
    }
}

void evenday(TaskList listing)
{
    for(int x = 0; x < listing.maxed; ++x)
    {
        if(listing.details[x].given.day % 2 != 0)
        {
            display(listing);
            printf("\n");
        }
    }
}

void done(TaskList *listing, int day, int month, int year)
{
    for(int a = 0; a < listing->counted; ++a)
    {
        if(day == listing->details[a].given.day && month == listing->details[a].given.month && year == listing->details[a].given.year)
        {
            for(int b = a; b < listing->counted; ++b)
            {
                listing->details[b] = listing->details[b + 1];
            }
            (listing->counted)--;
        }
    }
}

void menu()
{
    String menu[4] = {"Add School Task", "Delete School Task", "View All School Task", "Close Eyes"};

    printf("________Menu________\n");
    for(int x = 0; x < 4; ++x)
    {
        printf("|(%d) %s \n", x + 1, menu[x]);
    }
    printf("____________________\n\n");
}

#endif
