/* Implement NFA over alphabet {0,1} that accepts all strings ending with 01.
   A state in NFA may have multiple transitions for an input symbol. Such parallel
   computing can be better modeled with recursive functions. So, each transition from
   a state has been defined as a recursive function. */
#include<stdio.h>
#include<string.h>

char input[20]; // to store input string
int l;          // to store length of the input string
int flag;       // to decide accept or reject the input string

void q2(int i) {
    if (input[i] == '\0') {
        flag = 1;
    }
}

void q1(int i) {
    if (i < l) { // i is less than the length of the string
        if (input[i] == '0') {
            int k = i;
            k++;
            q0(k);
            q1(k);
        } else if (input[i] == '1') {
            i++;
            q2(i);
        }
    }
}

void q0(int i) {
    if (i < l) {
        if (input[i] == '0') {
            i++;
            q1(i);
        } else if (input[i] == '1') {
            i++;
            q0(i);
        }
    }
}

int main() {
    printf("\nEnter a string: ");
    gets(input);
    l = strlen(input);
    int i = 0;
    flag = 0;
    q0(i);
    if (flag == 1)
        printf("\nThe string is accepted.");
    else
        printf("\nThe string is not accepted.");
    return 0;
}

