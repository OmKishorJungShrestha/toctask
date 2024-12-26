#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32
#define MAX_LENGTH 100

int main() {
    // Array of built-in data types and C keywords
    char keywords[MAX_KEYWORDS][10] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while", "true", "false", "nullptr"
    };

    char c[MAX_LENGTH];
    char curr_state = 'A';
    
    printf("Enter a C code snippet (data type or variable name): ");
    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0';  // Remove newline character

    // Check if the input is a keyword
    int found = 0;
    int i;
    for ( i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(c, keywords[i]) == 0) {
            found = 1;  // Found a built-in type or keyword
            break;
        }
    }

    if (found) {
        printf("%s is a valid C keyword.\n", c);
    } else {
        // DFA to validate variable names
        int j = 0;
        while (c[j] != '\0') {
            switch (curr_state) {
                case 'A':  // Start state
                    if (isalpha(c[j]) || c[j] == '_') {
                        curr_state = 'B';  // Move to valid character state
                    } else {
                        curr_state = 'C';  // Invalid character
                    }
                    break;

                case 'B':  // Valid character state
                    if (isalnum(c[j]) || c[j] == '_') {
                        curr_state = 'B';  // Stay in valid character state
                    } else {
                        curr_state = 'C';  // Invalid character
                    }
                    break;

                case 'C':  // Dead state
                    curr_state = 'C';  // Stay in dead state
                    break;

                default:
                    break;
            }
            j++;  // Move to the next character
        }
    }

    // Final state check
    if (curr_state == 'B') {
        printf("%s is a valid C identifier.\n", c);
    } else {
        printf("%s is not a valid C identifier.\n", c);
    }

    return 0;
}

