#include <stdio.h>
#include <string.h>

int main() {
    char cities[5][50];
    int i, longest = 0;
    printf("Enter 5 city names:\n");
    for (i = 0; i < 5; i++) {
        fgets(cities[i], sizeof(cities[i]), stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0';
    }
    printf("\nCities:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", cities[i]);
        if (strlen(cities[i]) > strlen(cities[longest]))
            longest = i;
    }
    printf("\nLongest city: %s (length %zu)\n", cities[longest], strlen(cities[longest]));
    return 0;
}