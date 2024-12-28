#include <stdio.h>
#include <string.h>

// States enumeration
enum states { q0, q1, q2, q3, q4, qr };

int main() {
    char input[100];
    enum states curr_state = q0;
    int i;

    // Initialize input array with null characters
    for (i = 0; i < 100; i++) {
        input[i] = '\0';
    }

    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input if present
    input[strcspn(input, "\n")] = '\0';

    // Validate input: check for non-binary characters
    for (i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("\nInvalid string: contains characters other than 0 and 1.\n");
            return 1; // Exit on invalid input
        }
    }

    i = 0;
    while (1) {
        switch (curr_state) {
            case q0:
                if (input[i] == '0') {
                    curr_state = q1;
                    input[i] = 'x';  // Mark '0' as processed
                    i++;
                } else if (input[i] == 'y') {
                    curr_state = q3;  // Skip to q3 if all '0's are marked
                    i++;
                } else if (input[i] == '\0') {
                    curr_state = qr;  // Invalid transition if unmatched 0's and 1's
                } else {
                    curr_state = qr;  // Reject for invalid character
                }
                break;

            case q1:
                if (input[i] == '0') {
                    curr_state = q1;
                    i++;  // Skip over remaining '0's
                } else if (input[i] == '1') {
                    curr_state = q2;
                    input[i] = 'y';  // Mark '1' as processed
                    i--;
                } else if (input[i] == 'y') {
                    curr_state = q1;
                    i++;  // Continue if already processed
                } else {
                    curr_state = qr;  // Reject if no valid match for '1'
                }
                break;

            case q2:
                if (input[i] == '0') {
                    curr_state = q2;
                    i--;  // Move left to find next unmarked '0'
                } else if (input[i] == 'y') {
                    curr_state = q2;
                    i--;  // Continue left over processed '1's
                } else if (input[i] == 'x') {
                    curr_state = q0;  // Return to q0 to look for next pair
                    i++;
                } else {
                    curr_state = qr;  // Reject on invalid input
                }
                break;

            case q3:
                if (input[i] == 'y') {
                    curr_state = q3;
                    i++;  // Skip over all processed '1's
                } else if (input[i] == '\0') {
                    curr_state = q4;  // Accept if end of input reached
                } else {
                    curr_state = qr;  // Reject if unprocessed characters found
                }
                break;
        }

        // Termination condition for the loop
        if (curr_state == qr || curr_state == q4) {
            break;
        }
    }

    // Final state check
    if (curr_state == q4) {
        printf("\nThe string is accepted.\n");
    } else {
        printf("\nThe string is not accepted.\n");
    }

    return 0;
}
