#include <stdio.h>
/*
    Asks the age and 1st letter of their Name then calculates a score. Then total score is presented and certain lines are printed out
    Even score: A Balance Life
    Odd score: Trails and Tribulations

    Age:
    - Range from 25 to 40 and greater -> add 7 to the age
    - Range from 25 lower to 18 -> add 4 to the age
    - Range from 18 below to 1 -> add 2 to the age
    - If negative - "Invalid Age! Are you a sperm / egg? how?"

    # Note: age divided by the category score, then whole number is used to keep adding the score

    Letter:
    - If fav letter is the same with the 1st letter of their name increase 50%
    - All vowels are 10% increase
    - All consonant are 8% increase
*/

int main()
{
    int age;
    char first_letter, fav_letter;
    float total_Score;

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter 1st Letter of Your Name [Lowercase]: ");
    scanf("%c", &first_letter);

    printf("Enter Favorite Letter: ");
    scanf("%c", &fav_letter);

    return 0;
}