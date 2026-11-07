#include <stdio.h>
#include <string.h>

int main() {
    char first[30], last[30], full[70];
    printf("Enter first name: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';
    printf("Enter last name: ");
    fgets(last, sizeof(last), stdin);
    last[strcspn(last, "\n")] = '\0';
    full[0] = '\0';
    strcat(full, first);
    strcat(full, " ");
    strcat(full, last);
    printf("Full name: %s\n", full);
    return 0;
}