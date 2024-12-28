/* TOC Lab: Implement a NFA for L = { set of all strings over {0,1} such that strings start with 01 }.
   The program uses flag = 1 to indicate undefined transitions at a state. */
#include <stdio.h>
#include <string.h>

int main() {
    enum states { q0, q1, qf };     // Define states
    char input[20];                 // Input string array
    enum states curr_state = q0;    // Set initial state to q0
    int i = 0;
    int flag = 0;                   // Flag for undefined transitions

    printf("\nEnter a binary string: ");
    gets(input);
    char ch = input[i];
    
    while (ch != '\0') {
        switch (curr_state) {
            case q0:
                if (ch == '0')
                    curr_state = q1;
                else
                    flag = 1;
                break;
                
            case q1:
                if (ch == '1')
                    curr_state = qf;
                else
                    flag = 1;
                break;
                
            case qf:
                if (ch == '0' || ch == '1')
                    curr_state = qf;
                break;
        }
        
        if (flag)
            break;
        ch = input[++i];
    }
    
    if (curr_state == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);
        
    return 0;
}

