#include <stdio.h>

int main() {
    int number;
    
    // Input
    printf("Enter a number: ");
    scanf("%d", &number);

    // Output factors and highlight composite factors
    printf("Factors of %d: ", number);
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            // Print factor
            printf("%d ", i);

            // Highlight composite factors
            if (i != 1 && i != number) {
                printf("{%d} ", i);
            }
        }
    }

    printf("\n");

    return 0;
}
