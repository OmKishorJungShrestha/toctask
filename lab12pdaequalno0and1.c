#include <stdio.h>
#include <string.h>
#define MAX 100

enum states { q0, q1, qf };
void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states, char, char);

struct stack {
    char symbols[MAX];
    int top;
};

struct stack s;

int main() {
    char input[20];
    enum states curr_state = q0;
    s.top = -1;
    int i = 0;
    char ch = 'e';    // e indicating epsilon
    char st_top = 'e';
    int j;
    push('$');    // Initialize stack with bottom marker
    curr_state = delta(curr_state, ch, st_top);
    
    printf("\nEnter a binary string: ");
    scanf("%s", input);   // Using scanf instead of gets for safety

    // Validate input: check for non-binary characters
    for ( j = 0; j < strlen(input); j++) {
        if (input[j] != '0' && input[j] != '1') {
            printf("Invalid string: contains characters other than 0 and 1.\n");
            return 1;  // Exit the program on invalid input
        }
    }

    ch = input[i];
    st_top = get_stack_top();
    int c = 0;
    
    while (c < strlen(input)) {
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
        st_top = get_stack_top();
        c++;
    }

    // Final check with null character
    curr_state = delta(curr_state, '\0', get_stack_top());
    
    if (curr_state == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);
        
    return 0;
}

char get_stack_top() {
    if (s.top >= 0)
        return s.symbols[s.top];
    return 'e';
}

void push(char ch) {
    if (s.top < MAX - 1) {
        s.symbols[++s.top] = ch;
    } else {
        printf("\nStack Full!");
    }
}

void pop() {
    if (s.top >= 0) {
        s.top--;
    } else {
        printf("\nStack Empty!");
    }
}

enum states delta(enum states curr_state, char ch, char st_top) {
    switch (curr_state) {
        case q0:
            if (ch == 'e' && st_top == 'e') {
                return q1;
            }
            break;
            
        case q1:
            if (ch == '0' && (st_top == '$' || st_top == '0')) {
                push('0');
                return q1;
            } else if (ch == '1' && (st_top == '$' || st_top == '1')) {
                push('1');
                return q1;
            } else if ((ch == '1' && st_top == '0') || (ch == '0' && st_top == '1')) {
                pop();
                return q1;
            } else if (ch == '\0' && st_top == '$') {
                return qf;
            }
            break;
            
        case qf:
            break;
    }
    return curr_state;
}
