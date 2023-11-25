#include <stdio.h>

int main(){
    long long int binary = 0, hold_binary = 0, reverse_binary, rev = 0;
    int decimal, remainder, position = 1, count = 0, look_num, ren;
    
    printf("Enter Decimal: ");
    scanf("%d", &decimal);

    while (decimal != 0)
    {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * position;
        position *= 10;
    }

    hold_binary = binary;

    while (hold_binary != 0)
    {
        look_num = hold_binary % 10;
        if (look_num == 1)
        {
            count++;
        }
        hold_binary /= 10;
    }

    reverse_binary = binary * 10;

    while (reverse_binary > 0)
    {
        ren = reverse_binary % 10;
        rev = rev * 10 + ren;
        reverse_binary /= 10;
    }
    
    printf("Binary: %lld\n", binary);
    printf("Reverse Binary: %lld\n", rev);

    if (binary == rev)
    {
        printf("Status: A Palindrome\n");
    }
    else
    {
        printf("Status: Not A Palindrome\n");
    }
    
    printf("1 appeared %d times.\n", count);
    

    return 0;
}
