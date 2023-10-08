#include <stdio.h>

int main()
{
    char test_char;
    int test_num;

    printf("Hello my name is\nVoltaire Ratilla\n");

    printf("Enter a character (any): ");
    scanf("%c", &test_char);
    printf("Enter a integer (any): ");
    scanf("%d", &test_num);

    printf("You Entered %c and %d", test_char, test_num);

    return 0;
}