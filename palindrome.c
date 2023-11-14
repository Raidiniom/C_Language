#include <stdio.h>

int main()
{
    /*
        Palindrome: 
        
        
    */
    int number, store, check_num, count = 0;

    printf("Enter a long number: ");
    scanf("%d", &number);
    store = number;

    printf("Enter a number to find: ");
    scanf("%d", &check_num);
    
    while (store > 0)
    {
        int reminder = store % 10;
        if (check_num == reminder)
        {
            count++;
        }
        
        store /= 10;
    }

    printf("%d appeared %d times", check_num, count);

    return 0;
}