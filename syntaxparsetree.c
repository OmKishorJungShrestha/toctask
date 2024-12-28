//syntasparsetree:
#include<stdio.h>

int main() {
    FILE *fp;
    int i=0, j=0, k, l, row, col, s, x;
    char a[10][10], ch, main[50], search;
    fp = fopen("syntax.txt", "r+");

    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') {
            row = i;
            col = j;
            j = 0;
            i++;
        } else {
            a[i][j] = ch;
            j++;
        }
    }

    printf("\n");
    for(k = 0; k < row + 1; k++) {
        for(l = 0; l < col; l++)
            printf("%c ", a[k][l]);
        printf("\n");
    }

    j = 0;
    s = 0;
    x = 0;
    for(k = 0; k < row + 1; k++) {
        main[j++] = a[k][1];
        if(a[k][0] == 'e') {
            search = a[k][2];
            for(i = 0; i < j; i++) {
                if(main[i] == search) {
                    main[i] = main[j - 1];
                    j--;
                    break;
                }
            }
        } else {
            main[j++] = a[k][5];
            main[j++] = a[k][6];
            main[j++] = a[k][8];
            if(a[k][8] == 'e') {
                search = a[k][8];
                for(i = 0; i < j; i++) {
                    if(main[i] == search) {
                        main[i] = main[j - 1];
                        j--;
                        break;
                    }
                }
            }
        }
    }

    for(x = 1; x >= 0 && x <= 4; x++) {
        printf("\n\t%c: root -> %c", main[x - 3], main[x - 1]);
        if(main[x - 2] > 48 && main[x - 2] < 59)
            printf("%c:%c", main[x - 2], main[x - 2]);
        else
            printf("%c:%c", main[x - 2], main[x]);
        if(main[x] > 48 && main[x] < 59)
            printf("%c:%c", main[x], main[x]);
        else
            printf("%c:%c", main[x], main[x]);
    }

    return 0;
}



