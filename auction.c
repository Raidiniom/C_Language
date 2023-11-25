#include <stdio.h>

int main(){
    long long int num, num1, num2, i = 0;
    do{
    printf("Input a Number: ");
    scanf("%lld",&num);
        if(num > num1){
            num1 = num;
            num2 = num;
            i++;
        }
        if(num == 0){
            printf("\nProgram Ended due to an input of 0\n");
            printf("\nThe Greatest Number is : %lld",num1);
        }
        if(i == 3){
            printf("\nProgram Ended due to 3 changes in the Greatest Number\n");
            printf("\nThe Greatest Number is : %lld",num);
        }
    }while(i < 3 && num != 0);

    return 0;
}