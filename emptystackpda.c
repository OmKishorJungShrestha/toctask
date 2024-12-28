#include<stdio.h>
#include<string.h>
#define MAX 100

enum states {q0, q1, q2};

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
    char input[MAX];
    enum states curr_state = q0;
    s.top = -1;
    char ch;

    printf("\n Enter a binary string: ");
    gets(input);

    ch = input[0];
    push('Z');
    char stack_top = get_stack_top();

    int i = 0;
    while (ch != '\0') {
        char stack_top = get_stack_top();
        curr_state = delta(curr_state, ch, stack_top);
        ch = input[++i];
    }

    if (s.symbols[s.top] == 'Z') {
        printf("\n The string '%s' is accepted.", input);
    } else {
        printf("\n The string '%s' is not accepted.", input);
    }

    return 0;
}

enum states delta(enum states curr_state, char ch, char top) {
    switch(curr_state) {
        case q0:
            if (ch == '0' && top == 'Z') {
                curr_state = q0;
                push('X');
            } else if (ch == '0' && top == 'X') {
                curr_state = q0;
                push('X');
            } else if (ch == '1' && top == 'X') {
                curr_state = q1;
                pop();
            }
            break;

        case q1:
            if (ch == '1' && top == 'X') {
                curr_state = q1;
                pop();
            } else if (ch == '1' && top == 'Z') {
                curr_state = q2;
                pop();
            }
            break;

        case q2:
            break;
    }
    return curr_state;
}

char get_stack_top() {
    return s.symbols[s.top];
}

void push(char ch) {
    if (s.top < MAX - 1) {
        s.symbols[++s.top] = ch;
    } else {
        printf("\n Stack Full.");
    }
}

void pop() {
    if (s.top > -1) {
        s.symbols[s.top--] = '\0';
    } else {
        printf("\n Stack Empty.");
    }
}

