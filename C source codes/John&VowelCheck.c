#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

int main()
{
    char names[5][MAX];
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char last;
    int count_john = 0, check_vowel = 0;

    printf("Enter 5 names: \n");
    for(int i = 0; i < 5; ++i)
    {
        scanf(" %[^\n]", names[i]);
    }

    // john name check
    for(int x = 0; x < 5; ++x)
    {
        if(strcmp(names[x], "john") == 0)
        {
            count_john++;
        }
    }

    // vowel last letter name
    for(int x = 0; x < 5; ++x)
    {
        last = names[x][strlen(names[x]) - 1];
        for(int i = 0; i < sizeof(vowels) / sizeof(vowels[0]); ++i)
        {
            if(last == vowels[i])
            {
                check_vowel++;
                break;
            }
        }
    }


    if(count_john > 0)
    {
        printf("John: %d\n", count_john);
    }
    else
    {
        printf("No John Found!");
    }

    if(check_vowel > 0)
    {
        printf("Vowel: %d\n", check_vowel);
    }
    else
    {
        printf("No Vowels Found!");
    }
    
    return 0;
}

/*
    
    for(int x = 0; x < 5; ++x)
    {
        printf("%s ", names[x]);
    }
*/