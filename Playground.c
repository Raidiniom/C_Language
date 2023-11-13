#include <stdio.h>

int main()
{
    int age;
    char first_letter;
    float total_Score;

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter 1st Letter of Your Name [Lowercase]: ");
    scanf("%c", &first_letter);

    if (age <= 30 && age >= 25)
    {
        total_Score += 24;
    }
    else if (age <= 24 && age >= 18)
    {
        total_Score += 10.55;
    }
    else if (age < 18 && age > 0)
    {
        total_Score += 5.9;
    }
    else
    {
        total_Score += 0;
    }
    

    return 0;
}