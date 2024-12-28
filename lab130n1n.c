/* TOC Lab: Implement a PDA for L = {set of all strings over {0,1} such that 0^n1^n} 
   acceptance by final state */

#include <stdio.h>
#include <string.h>
#define MAX 100

// Enum to define the states of the PDA
enum states { q0, q1, q2, qf, qr };

// Stack structure
struct stack {
    char symbols[MAX];
    int top;
} s;

// Function prototypes
void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states s, char ch, char st_top);

int main() {
    char input[20];
    enum states curr_state = q0;
    s.top = -1;
    
    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character if any

    // Initial transition to push '$' and move to q1
    curr_state = delta(curr_state, 'e', 'e');

    int i = 0;
    char ch = input[i];
    char st_top;

    while (curr_state != qf && curr_state != qr && i < strlen(input)) {
        st_top = get_stack_top();
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
    }

    // Final transition to check for acceptance at the end of the input
    if (curr_state != qr) {
        st_top = get_stack_top();
        curr_state = delta(curr_state, '\0', st_top);
    }

    if (curr_state == qf)
        printf("\nThe string %s is accepted.\n", input);
    else
        printf("\nThe string %s is not accepted.\n", input);

    return 0;
}

// Transition function for the PDA
enum states delta(enum states s, char ch, char st_top) {
    enum states curr_state = qr; // default to qr for undefined transition
    switch (s) {
        case q0:
            if (ch == 'e' && st_top == 'e') {
                curr_state = q1;
                push('$');
            }
            break;

        case q1:
            if (ch == '0' && (st_top == '$' || st_top == '0')) {
                curr_state = q1;
                push('0');  // Push '0' for each '0' read
            } else if (ch == '1' && st_top == '0') {
                curr_state = q2;
                pop();  // Start popping '0's for each '1' read
            } else {
                curr_state = qr;
            }
            break;

        case q2:
            if (ch == '1' && st_top == '0') {
                curr_state = q2;
                pop();  // Continue popping '0's for each '1'
            } else if (ch == '\0' && st_top == '$') {
                curr_state = qf;  // Accept if input ends and only '$' remains
                pop();
            } else {
                curr_state = qr;
            }
            break;
    }
    return curr_state;
}

// Stack functions
void push(char ch) {
    if (s.top < MAX - 1) {
        s.symbols[++s.top] = ch;
    } else {
        printf("\nStack Full.");
    }
}

void pop() {
    if (s.top >= 0) {
        s.top--;
    } else {
        printf("\nStack Empty.");
    }
}

char get_stack_top() {
    if (s.top >= 0) {
        return s.symbols[s.top];
    }
    return 'e'; // Return 'e' if the stack is empty
}

