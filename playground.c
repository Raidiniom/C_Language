#include <stdio.h>
#include <string.h>

typedef char String[20];

int main() {
    String name;
    String nam;

    printf("Enter the first string: ");
    scanf("%[^\n]%*c", name); // Read until newline and discard newline

    printf("Enter the second string: ");
    scanf("%[^\n]%*c", nam); // Read until newline and discard newline

    printf("\n --> %s <-- \n", name);
    printf("\n --> %s <-- \n", nam);

    return 0;
}
