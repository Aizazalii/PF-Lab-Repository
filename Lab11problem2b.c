#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    char temp;
    if (start >= end) {
        return;
    }
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    return 0;
}