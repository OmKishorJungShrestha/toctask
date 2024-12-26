#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000  // Define a maximum length for the input

int main() {
    char c[MAX_LENGTH];  // Array to store the input C code snippet
    int curr_state = 'A';  // Start state

    printf("Enter C code snippet (end with Ctrl+D): \n");

    // Use fgets to safely read input
    fgets(c, sizeof(c), stdin);

    int i = 0;
    while (c[i] != '\0') {  // Read characters until end of string
        switch (curr_state) {
            case 'A':  // Start state
                if (c[i] == '/') {
                    curr_state = 'B';  // Move to state B (looking for another '/')
                } else {
                    curr_state = 'D';  // Enter dead state for any other character
                }
                break;

            case 'B':  // After reading '/', looking for another '/'
                if (c[i] == '/') {
                    curr_state = 'C';  // Move to single-line comment state
                } else {
                    curr_state = 'D';  // Enter dead state if not '/'
                }
                break;

            case 'C':  // Inside single-line comment
                // Remain in state C for any character until end of line
                if (c[i] == '\n' || c[i] == '\0') {
                    curr_state = 'C';  // End of single-line comment
                }
                break;

            case 'D':  // Dead state (invalid sequence)
                curr_state = 'D';// Remain in dead state for any invalid input
                break;

            default:
                break;
        }
        i++;  // Move to the next character
    }

    // Final check: if the last state was a comment ending state
    if (curr_state == 'C' ) {
        printf("Single-line comment accepted.\n");
    } else {
        printf("Single-line comment not accepted.\n");
    }

    return 0;
}

