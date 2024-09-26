#include <stdio.h>
#include <stdlib.h>

int main() {
    int id = 10;
    int hash = 0;

    for (int i = id; i > 0; i--)
    {
        // ((10 >> i) % 2 != 0) ? printf("%d", i), hash += i : printf("0");
        printf("%d ", 10 >> i);
    }
    

    return 0;
}

// 0 1 2 3 4 5
// 0 1 2 4 8 16