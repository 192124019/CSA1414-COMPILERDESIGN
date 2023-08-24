#include <stdio.h>

int main() {
    char str[100]; // Input string with size 100
    int words = 0, newline = 0, characters = 0; // Counter variables

    printf("Enter a string (use '~' to end):\n");
    scanf("%[^~]", str); // scanf formatting

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            words++;
        } else if (str[i] == '\n') {
            newline++;
            words++; // New words start on a new line (corner case)
        }
        characters++; // Count characters regardless of space or newline
    }

    if (characters > 0) { // Corner case
        words++;
        newline++;
    }

    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", newline);
    printf("Total number of characters: %d\n", characters);

    return 0;
}
