#include <stdio.h>
#include <stdlib.h>

int main() {
    char c[100];  // Array to hold the input binary string
    printf("Enter a binary string: ");
    scanf("%s", c);

    char curr_state = 'A';  // Start in state A
    int j = 0;              // Initialize index for string traversal

    // Check for invalid characters in the string
    while (c[j] != '\0') {
        if (c[j] != '0' && c[j] != '1') {
            printf("Invalid string: contains characters other than 0 and 1.\n");
            return 1;  // Exit the program on invalid input
        }
        j++;  // Move to the next character
    }

    // Reset index for state processing
    j = 0;

    // Process the input string using DFA logic
    while (c[j] != '\0') {
        switch (curr_state) {
            case 'A':  // Start state
                if (c[j] == '0') {
                    curr_state = 'B';  // Transition to state B
                } else {
                    curr_state = 'A';  // Stay in state A on '1'
                }
                break;
            case 'B':  // After reading '0'
                if (c[j] == '0') {
                    curr_state = 'B';  // Stay in B on '0'
                } else {
                    curr_state = 'C';  // Transition to state C on '1'
                }
                break;
            case 'C':  // After reading '01'
                if (c[j] == '0') {
                    curr_state = 'B';  // Transition to B on '0'
                } else {
                    curr_state = 'A';  // Stay in A on '1'
                }
                break;
            default:
                break;  // Handle unexpected cases gracefully
        }
        j++;  // Move to the next character
    }

    // Final acceptance condition
    if (curr_state == 'C') {
        printf("The string is accepted (it ends with '01').\n");
    } else {
        printf("The string is not accepted (it does not end with '01').\n");
    }

    return 0;
}

