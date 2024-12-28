#include <stdio.h>
#include <stdbool.h>

enum states { q0, q1, q2, qf };

// Transition function definition
enum states delta(enum states curr_state, char ch) {
    switch (curr_state) {
        case q0:
            if (ch == '0') return q1;
            else return q0;
        case q1:
            if (ch == '0') return q2;
            else return q0;
        case q2:
            if (ch == '1') return qf;
            else return q2;
        case qf:
            return qf;
        default:
            return q0; // Default case (shouldn't reach here)
    }
}

// Function to check if a string contains only binary digits
bool is_binary(const char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '0' && string[i] != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    printf("\nEnter a binary string: ");
    scanf("%s", string);

    // Validate the input
    if (!is_binary(string)) {
        printf("\nThe string contains non-binary characters. Please enter a valid binary string.\n");
        return 0;
    }

    // Process the string
    while ((ch = string[i++]) != '\0') {
        curr_state = delta(curr_state, ch);
    }

    // Check if the string is accepted
    if (curr_state == qf) {
        printf("\nThe string '%s' is valid.\n", string);
    } else {
        printf("\nThe string '%s' is not valid.\n", string);
    }

    return 0;
}
