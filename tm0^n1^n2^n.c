#include <stdio.h>

// States enumeration
enum states { q0, q1, q2, q3, q4, q5, q6, qr };

int main() {
    char input[100];
    enum states curr_state = q0;
    int i;

    // Initialize input array with null characters
    for (i = 0; i < 100; i++) {
        input[i] = '\0';
    }

    printf("\nEnter a ternary string (containing only 0, 1, 2): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input if present
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    i = 0;
    while (1) {
        switch (curr_state) {
            case q0:
                if (input[i] == '0') {
                    curr_state = q1;
                    input[i] = 'x';  // Mark 0 as processed
                    i++;
                } else if (input[i] == 'y') {
                    curr_state = q4;  // Skip to q4 if all 0's and 1's are marked
                    i++;
                } else if (input[i] == '\0') {
                    curr_state = qr;  // Invalid transition
                } else {
                    curr_state = qr;  // Reject for invalid characters
                }
                break;

            case q1:
                if (input[i] == '0') {
                    curr_state = q1;
                    i++;  // Skip over remaining 0's
                } else if (input[i] == '1') {
                    curr_state = q2;
                    input[i] = 'y';  // Mark 1 as processed
                    i--;
                } else if (input[i] == 'y') {
                    curr_state = q1;
                    i++;
                } else {
                    curr_state = qr;  // Reject if no valid match for 1
                }
                break;

            case q2:
                if (input[i] == '0') {
                    curr_state = q2;
                    i--;  // Move left to find next unmarked 0
                } else if (input[i] == 'y') {
                    curr_state = q2;
                    i--;
                } else if (input[i] == 'x') {
                    curr_state = q0;  // Return to q0 to look for next pair
                    i++;
                } else {
                    curr_state = qr;
                }
                break;

            case q4:
                if (input[i] == 'y') {
                    curr_state = q4;
                    i++;  // Skip over all marked 1's
                } else if (input[i] == '2') {
                    curr_state = q5;
                    input[i] = 'z';  // Mark 2 as processed
                    i--;
                } else if (input[i] == '\0') {
                    curr_state = qr;  // Reject if 2's are missing
                } else {
                    curr_state = qr;  // Reject for invalid characters
                }
                break;

            case q5:
                if (input[i] == 'y') {
                    curr_state = q5;
                    i--;  // Move left to find next unmarked 1
                } else if (input[i] == 'z') {
                    curr_state = q5;
                    i--;
                } else if (input[i] == 'x') {
                    curr_state = q6;  // Move to q6 if all 2's are matched
                    i++;
                } else {
                    curr_state = qr;
                }
                break;

            case q6:
                if (input[i] == 'z') {
                    curr_state = q6;
                    i++;  // Skip over all marked 2's
                } else if (input[i] == '\0') {
                    curr_state = q4;  // Accept if reached the end of input
                } else {
                    curr_state = qr;  // Reject for invalid characters
                }
                break;

            default:
                curr_state = qr;  // Reject in case of unexpected errors
                break;
        }

        // Termination condition for the loop
        if (curr_state == qr || curr_state == q6) {
            break;
        }
    }

    // Final state check
    if (curr_state == q6) {
        printf("\nThe string is accepted.\n");
    } else {
        printf("\nThe string is not accepted.\n");
    }

    return 0;
}
