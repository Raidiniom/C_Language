#include <stdio.h>
/*Imitate the string functions without using the functions itself*/

typedef char String[50];

int main()
{
    String input1, input2;

    printf("Enter string 1: ");
    gets(input1);
    printf("Enter string 2: ");
    gets(input2);

    printf("Input String 1: %s\nInput String 2: %s", input1, input2);

    return 0;
}