#include <stdio.h>
#include <string.h>

void printPrefixes(char *str) {
    int len = strlen(str);
    int i, j;  // Declare loop variables outside the for loop

    printf("Prefixes:\n");
    for (i = 1; i <= len; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void printSuffixes(char *str) {
    int len = strlen(str);
    int i, j;  // Declare loop variables outside the for loop

    printf("Suffixes:\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void printSubstrings(char *str, int start, int end) {
    int len = strlen(str);
    int i;  // Declare loop variable outside the for loop

    if (start < 0 || end >= len || start > end) {
        printf("Invalid start or end positions.\n");
        return;
    }

    printf("Substring from index %d to %d: ", start, end);
    for (i = start; i <= end; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    int choice;
    int start, end;

    printf("Enter a string: ");
    scanf("%s", str);  // Read user input for the string

    while (1) {
        printf("\nMenu:\n");
        printf("1. Print Prefixes\n");
        printf("2. Print Suffixes\n");
        printf("3. Print Specific Substring\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printPrefixes(str);
                break;
            case 2:
                printSuffixes(str);
                break;
            case 3:
                printf("Enter starting index for substring: ");
                scanf("%d", &start);
                printf("Enter ending index for substring: ");
                scanf("%d", &end);
                printSubstrings(str, start, end);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

