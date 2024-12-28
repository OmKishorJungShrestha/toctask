//contextfreegrammar
#include <stdio.h>
#include <string.h>

int i, j, k, m, n = 0, p, nv, z = 0, x = 0;
char str[10], temp[20],temp1[20], temp2[20], temp3[20];

struct prod {
    char lhs[10], rhs[10][10];
    int n;
} pro[10];

void finder() {int t,k,l,j;
    for (k = 0; k < n; k++) {
        if (temp[j] == pro[k].lhs[0]) {
            for (t = 0; t < pro[k].n; t++) {
                for (l = 0; l < 20; l++) temp2[l] = '\0';
                for (l = 1; l < strlen(temp); l++) temp2[l - 1] = temp[l];
                for (l = 0; l < 20; l++) temp[l] = '\0';
                for (l = 0; l < strlen(pro[k].rhs[t]); l++) temp[l] = pro[k].rhs[t][l];
                strcat(temp, temp2);
                if (strcmp(temp, str) == 0) return;
                if (str[j] >= 'A' && str[j] <= 'Z') finder();
                break;
            }
            break;
        }
    }
}

int main() {
    FILE *fp;
    // char path[] = "C:\\Users\\JohnDoe\\Desktop\\MyFolder\\input.txt"; 
    fp = fopen("input.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%s%s", pro[n].lhs, pro[n].rhs[0]);
        if (strcmp(pro[n].lhs, pro[n - 1].lhs) == 0) {
            pro[n - 1].n++;
            strcpy(pro[n - 1].rhs[pro[n - 1].n], pro[n].rhs[0]);
        } else {
            pro[n].n = 0;
            n++;
        }
    }
    fclose(fp);

    printf("\nTHE GRAMMAR IS AS FOLLOWS:\n\n");
    for (i = 0; i < n; i++) {
        printf("%s->", pro[i].lhs);
        for (j = 0; j <= pro[i].n; j++) printf("%s|", pro[i].rhs[j]);
        printf("\b \n");
    }

    while (1) {
        for (i = 0; i < 10; i++) str[i] = '\0';
        printf("\nENTER ANY STRING (0 for EXIT): ");
        scanf("%s", str);
        if (str[0] == '0') exit(0);
        for (i = 0; i < 10; i++) temp[i] = '\0';
        strcpy(temp, str);

        for (i = 0; i < strlen(str); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') finder();
        }

        if (strcmp(str, temp) == 0) {
            printf("\n\nTHE STRING can be PARSED");
        } else {
            printf("\n\nTHE STRING can NOT BE PARSED");
        }
    }

    return 0;
}



