#include <stdio.h>
#include <stdlib.h>

char *modded(char str[]);

int main()
{
    char text[25], *mtext;

    printf("Enter a string: ");
    scanf(" %[^\n]", text);

    mtext = modded(text);

    printf("Modified string: %s", mtext);


    return 0;
}


char *modded(char str[])
{
    char *here = (char*)malloc(25);
    
    int x = 0, i = 0;
    for(; str[x] != '\0'; ++x)
    {
        if(str[x] != ' ')
        {
            here[i++] = str[x];
        }
    }
    here[x] = '\0';

    return here;
}