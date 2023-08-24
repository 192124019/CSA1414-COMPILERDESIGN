#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[31][10] = {
        "main", "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef",
        "unsigned", "void", "while"
    };

    int i, flag = 0;
    for (i = 0; i < 31; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=(){};";  // Include parentheses and semicolon
    FILE *fp;
    int i, j = 0;
    
    fp = fopen("flex_input.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        for (i = 0; i < 12; ++i) {  // Adjusted the loop range
            if (ch == operators[i]) {
                printf("%c is operator\n", ch);
                break;  // Break out of the loop after finding an operator
            }
        }

        if (isalnum(ch) || ch == '_') {  // Include underscore for identifiers
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1) {
                printf("%s is keyword\n", buffer);
            } else {
                printf("%s is identifier\n", buffer);
            }
        }
    }
    fclose(fp);
    return 0;
}
