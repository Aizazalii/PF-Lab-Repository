#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    char *p = strchr(sentence, 'a');
    if (p != NULL)
        printf("First 'a' found at index %ld\n", p - sentence);
    else
        printf("No 'a' found\n");
    if (strstr(sentence, "good") != NULL)
        printf("Word 'good' found.\n");
    else
        printf("Word 'good' not found.\n");
    return 0;
}