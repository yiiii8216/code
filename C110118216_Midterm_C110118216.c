//C110118216 IM 2rd Huang Yi Qin
//Blackjack Card-Counts by C Programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//s(黑桃)h(心)d(方塊)s(梅花)
char *card_type[4] = {"S", "H", "D", "C"};
int ca1[] = {2, 3, 4, 5, 6};
int ca2[] = {7, 8, 9};
//char *car3[5] = {"1", "10", "11", "12", "13"};

int n;

int main() {
    int n;
    scanf("%d", &n);
    int cardnum = n * 52;
    int (*poker)[2] = malloc(sizeof(int) * cardnum * 2);
    int *count = malloc(sizeof(int) * 5);
    cards(n, cardnum, poker, count);
    display(cardnum,poker);
    counting(cardnum, poker, ca1, ca2);
    free(poker);
    free(count);
    return 0;
}
void cards(int n, int num, int (*poker)[2], int *count) {
    int i, j, t, p;
    srand((unsigned)time(NULL));
for(j=1;j<=n;j++){
        for(i=0; i<num; i++) {
        p = rand() % 13 + 1;
        t = rand() % 4;
        poker[i][1] = t;
        poker[i][0] = p;
    }
}
}


void counting(int num, int (*poker)[2], int array2[], int array3[],int *count) {
    int i, c1 =count[2], c2 =count[3], c3 =count[4], sc =count[2], j;
    for (i = 0; i < num; i++) {
        int found = 0;
        for (j = 0; j < sizeof(array2); j++) {
            if (poker[i][0] == array2[j]) {
                c1++;
                sc++;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (j = 0; j < sizeof(array3); j++) {
                if (poker[i][0] == array3[j]) {
                    c2++;
                    sc += 0;
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            c3++;
            sc--;
        }
    }
    printf("\n%d,%d,%d,%d", c1, c2, c3, sc);
}
void display(int a,int (*poker)[2]){
    printf("Poker\tPoint\tCount\tCategory 1\tCategory 2\tCategory 3\t\n");
 for(int i=0; i<a; i++) {
        printf("%s%d", card_type[poker[i][1]],poker[i][0]);
        sleep(1);
    }

}
