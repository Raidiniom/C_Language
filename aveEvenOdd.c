#include <stdio.h>

int main(){
    int list_num[] = {4, 6, 5, 4, 1, 8, 6, 2, 3,11};
    int count_even = 0, count_odd = 0, sum_even, sum_odd, ave_even, ave_odd;

    for (int i = 0; i < sizeof(list_num)/sizeof(int); ++i){
        if (list_num[i] % 2 == 0)
        {
            sum_even += list_num[i];
            count_even++;
        }
        else
        {
            sum_odd += list_num[i];
            count_odd++;
        }
    }

    ave_even = sum_even / count_even;
    ave_odd = sum_odd / count_odd;

    printf("Even part: %d %d %d", ave_even, sum_even, count_even);
    printf("\nOdd part: %d %d %d", ave_odd, sum_odd, count_odd);
    
    return 0;
}