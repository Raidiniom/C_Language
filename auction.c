#include <stdio.h>

int main(){
    int num;
    int x = 0;
    int y = 0;
    int i = 0;

    do{
        printf("Input a Number: ");
        scanf("%d",&num);
         if(i == 0 || num > x ){
            y = num;
            x = num;
            i++;
        }
    }
    while(num != 0 && i != 3);
    printf("\n");

    if(i == 3){
        printf("Program Ended due to 3 changes in the Greatest Number\n");
    }
    else
        printf("Program Ended due to an input of 0\n");

    printf("\nThe Greatest Number is : %d",y);

    return 0;
}