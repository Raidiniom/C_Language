#include <stdio.h>

int main()
{
    int subjects, exams, grade, total = 0, average;

    printf("Enter No. of Subjects: ");
    scanf("%d", &subjects);

    printf("Enter No. of Exams: ");
    scanf("%d", &exams);

    for (int x = 1; x <= subjects; x++)
    {
        for (int y = 1; y <= exams; y++)
        {
            printf("Enter grade for Sub %d - Exa %d: ", x, y);
            scanf("%d", &grade);
            total += grade;
        }
        
    }

    average = total / (subjects * exams);

    printf("Total: %d\n", total);
    printf("Average: %d\n", average);
    

    return 0;
}