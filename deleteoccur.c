#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 6

typedef struct {
    int *arry;
    int element;
    int count;
} Array;

void display(Array input);
bool deloccur(Array *input, int element);
bool delalloccur(Array *input, int element);

int main()
{
    Array arry1;
    int todelete;

    printf("Enter size of the array: ");
    scanf("%d", &arry1.count);

    arry1.arry = (int*) malloc(arry1.count * sizeof(int));

    printf("Enter %d elements: \n", arry1.count);

    for (int i = 0; i < arry1.count; ++i)
    {
        scanf("%d", &arry1.arry[i]);
    }

    display(arry1);

    printf("\nElement to delete: ");
    scanf("%d", &todelete);

    deloccur(&arry1, todelete);

    display(arry1);


    return 0;
}

bool deloccur(Array *input, int element)
{
    for (int i = 0; i < max; ++i)
    {
        if (input->arry[i] == element)
        {
            for (int j = i; j < max - 1; ++j)
            {
                input->arry[j] = input->arry[j + 1];
            }
            (input->count)--;
            return true;
            break;
        }
    }
    return false;
}

bool delalloccur(Array *input, int element)
{
    for (int i = 0; i < input->count; ++i)
    {
        if (input->arry[i] == element)
        {
            for (int j = i; j < input->count - 1; ++j)
            {
                input->arry[j] = input->arry[j + 1];
            }
            (input->count)--;
            i--;
        }
    }
    return true;
}

void display(Array input)
{
    printf("{");
    for (int i = 0; i < input.count; ++i)
    {
        printf("%d", input.arry[i]);
        if (i != input.count - 1)
        {
            printf(", ");
        }
    }
    printf("}");
}
