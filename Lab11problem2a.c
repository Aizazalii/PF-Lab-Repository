#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int year;
    float rating;
};

int main() {
    struct Movie m[50];
    int count = 0;
    int choice, i;
    char searchGenre[30];

    while (1) {
        printf("\n1. Add Movie\n2. Search by Genre\n3. Display All Movies\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter title: ");
            scanf(" %[^\n]", m[count].title);
            printf("Enter genre: ");
            scanf(" %[^\n]", m[count].genre);
            printf("Enter director: ");
            scanf(" %[^\n]", m[count].director);
            printf("Enter release year: ");
            scanf("%d", &m[count].year);
            printf("Enter rating: ");
            scanf("%f", &m[count].rating);
            count++;
            printf("Movie added!\n");
        } 
        else if (choice == 2) {
            printf("Enter genre to search: ");
            scanf(" %[^\n]", searchGenre);
            printf("\n--- Search Results ---\n");
            for (i = 0; i < count; i++) {
                if (strcmp(m[i].genre, searchGenre) == 0) {
                    printf("Title: %s | Director: %s | Year: %d | Rating: %.1f\n", m[i].title, m[i].director, m[i].year, m[i].rating);
                }
            }
        } 
        else if (choice == 3) {
            printf("\n--- All Movies ---\n");
            for (i = 0; i < count; i++) {
                printf("Title: %s | Genre: %s | Director: %s | Year: %d | Rating: %.1f\n", m[i].title, m[i].genre, m[i].director, m[i].year, m[i].rating);
            }
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}