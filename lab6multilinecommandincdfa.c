#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000  // Define a maximum length for the input

int main() {
    char c[MAX_LENGTH];  // Array to store the input C code snippet
    char input[101];     // Temporary buffer for reading input lines
    int curr_state = 'A';  // Start state

    printf("Enter C code snippet (end with Ctrl+D): \n");

    gets(c);

    int i = 0;
    while (c[i] != '\0') {  // Read characters until end of string
        switch (curr_state) {
            case 'A':  // Start state
                if (c[i] == '/') {
                    curr_state = 'B';  // Move to state B (looking for '*')
                } else {
                    curr_state = 'F';  // Enter dead state for any other character
                }
                break;

            case 'B':  // After reading '/', looking for '*'
                if (c[i] == '*') {
                    curr_state = 'C';  // Move to multi-line comment state
                } else {
                    curr_state = 'F';  // Enter dead state if not '*' or '/'
                }
                break;

            case 'C':  // Inside multi-line comment
                if (c[i] == '*') {
                    curr_state = 'D';  // Potential end of multi-line comment
                }
                // Remain in state C for any other character
                break;

            case 'D':  // After reading '*', looking for '/'
                if (c[i] == '/') {
                    curr_state = 'E';  // Multi-line comment ended
                } else if (c[i] == '*') {
                    curr_state = 'D';  // Stay in comment state
                } else {
                    curr_state = 'C';  // If any other character, remain in comment state
                }
                break;

            case 'E':  // Acceptance state (valid comment)
                curr_state = 'F';// Once in acceptance state, remain there
                break;

            case 'F':  // Dead state (invalid sequence)
               curr_state = 'F'; // Remain in dead state for any invalid input
                break;

            default:
                break;
        }
        i++;  // Move to the next character
    }

    // Final check: if the last state was a comment ending state
    if (curr_state == 'E') {
        printf("Multi-line comment accepted.\n");
    } else {
        printf("Multi-line comment not accepted.\n");
    }

    return 0;
}

