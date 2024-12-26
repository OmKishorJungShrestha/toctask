#include <stdio.h>
#include <stdlib.h>

int main() {
    char c[100];
    printf("Enter a binary string: ");
    scanf("%s", c);

    char curr_state = 'A';  // Start in state A
    int j = 0;

    while (c[j] != '\0') {
        if (c[j] != '0' && c[j] != '1') {
            printf("Invalid string: contains characters other than 0 and 1.\n");
            return 1;  // Exit the program on invalid input
        }
        j++;  // Move to the next character
    }

    j = 0;  // Reset index for state processing

    while (c[j] != '\0') {
        switch (curr_state) {
            case 'A':  // Start state, expecting '0'
                if (c[j] == '0') {
                    curr_state = 'B';  // Transition to state B
                } else {
                    curr_state = 'E';  // Transition to dead state E
                }
                break;
            case 'B':  // After reading '0', expecting '1'
                if (c[j] == '1') {
                    curr_state = 'C';  // Transition to state C
                } else {
                    curr_state = 'E';  // Transition to dead state E
                }
                break;
            case 'C':  // After reading '01', expecting '0'
                if (c[j] == '0') {
                    curr_state = 'D';  // Transition to accepting state D
                } else {
                    curr_state = 'E';  // Transition to dead state E
                }
                break;
            case 'D':  // Accepting state after reading '010'
                curr_state = 'D';  // Stay in accepting state on any input
                break;
            case 'E':  // Dead state
                // Stay in dead state on any input
                break;
            default:
                break;  // Handle unexpected cases gracefully
        }
        j++;  // Move to the next character
    }

    // Final acceptance condition
    if (curr_state == 'D') {
        printf("The string is accepted (it starts with '010').\n");
    } else {
        printf("The string is not accepted (it does not start with '010').\n");
    }

    return 0;
}

