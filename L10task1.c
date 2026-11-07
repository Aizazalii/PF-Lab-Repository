#include <stdio.h>
#include <string.h>

int main() {
    char name[50], copy[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Length: %zu\n", strlen(name));
    strcpy(copy, name);
    printf("Copy: %s\n", copy);
    printf("sizeof array: %zu\n", sizeof(name));
    return 0;
}