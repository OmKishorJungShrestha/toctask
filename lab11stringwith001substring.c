#include <stdio.h>
#include <string.h>

char input[20];  // to store input string
int l;           // to store length of the input string
int flag;        // to decide accept or reject the input string

// Function prototypes
void q0(int i);  // initial state
void q1(int i);  // state after seeing first '0'
void q2(int i);  // state after seeing second '0'
void q3(int i);  // final state (after seeing "001")

// Final state q3 (accepting state)
void q3(int i) {
    flag = 1;  // mark as accepted
    if(i < l) {   // can read more input and stay in accepting state
        i++;
        q3(i);
    }
}

// State q2 - looking for '1' after "00"
void q2(int i) {
    if(i < l) {
        if(input[i] == '1') {  // found "001"
            i++;
            q3(i);
        }
        else if(input[i] == '0') {  // another '0', stay in q2
            i++;
            q2(i);
        }
    }
}

// State q1 - looking for second '0'
void q1(int i) {
    if(i < l) {
        if(input[i] == '0') {  // found second '0'
            i++;
            q2(i);
        }
        else if(input[i] == '1') {  // on '1', go back to start
            i++;
            q0(i);
        }
    }
}

// Initial state q0
void q0(int i) {
    if(i < l) {
        if(input[i] == '0') {  // found first '0'
            i++;
            q1(i);    // move to q1
            q0(i);    // also try staying in q0
        }
        else if(input[i] == '1') {  // on '1', stay in q0
            i++;
            q0(i);
        }
    }
}

int main() {
    printf("\nEnter a string: ");
    gets(input);
    l = strlen(input);
    flag = 0;
    
    q0(0);  // Start from initial state
    
    if(flag == 1)
        printf("\nThe string is accepted (contains '001').");
    else
        printf("\nThe string is not accepted (does not contain '001').");
    
    return 0;
}
