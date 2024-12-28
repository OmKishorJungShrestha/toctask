#include <stdio.h>

// States declarations
enum states {q0, q1, qf, qd};

// Transition function declaration
enum states delta(enum states s, char ch);

// Function to check if character is binary
int is_binary(char ch) {
    return (ch == '0' || ch == '1');
}

int main() {
    char input[20];
    enum states curr_state = q0;
    int i = 0;
    int valid = 1;  // Flag for valid binary input

    printf("\nEnter a binary string (only 0s and 1s):\n");
    gets(input);

    // First check if input is binary
    for(i = 0; input[i] != '\0'; i++) {
        if(!is_binary(input[i])) {
            valid = 0;
            break;
        }
    }

    if(!valid) {
        printf("\nError: Input must contain only 0s and 1s\n");
        return 1;
    }

    // Process valid binary input
    i = 0;
    char ch = input[i];
    while(ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if(curr_state == qf)
        printf("\nThe string %s is accepted.\n", input);
    else
        printf("\nThe string %s is not accepted.\n", input);

    return 0;
}

// Transition Function
enum states delta(enum states s, char ch) {
    enum states curr_state;
    switch(s) {
        case q0:
            if(ch=='0')
                curr_state = q1;
            else
                curr_state = qd;
            break;
        case q1:
            if(ch=='1')
                curr_state = qf;
            else
                curr_state = qd;
            break;
        case qf:
            if(ch=='0')
                curr_state = qf;
            else
                curr_state = qf;
            break;
        case qd:
            if(ch=='0')
                curr_state = qd;
            else
                curr_state = qd;
            break;
    }
    return curr_state;
}
