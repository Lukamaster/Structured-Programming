#include <stdio.h>
#define MAX 100

int parcom(int a) {

    if(a == 0) {
        return 0;
    }
    if((a%10) % 2 == 0) {
        int digit = (a%10) + 1;
        int parcomp = parcom(a/10);
        parcomp*=10;
        parcomp+=digit;
        return parcomp;
    } else {
        int digit = (a%10) - 1;
        int parcomp = parcom(a/10);
        parcomp*=10;
        parcomp+=digit;
        return parcomp;
    }
}

int main() {

    int k, pairs[MAX] = {};

    while(scanf("%d", &pairs[k])) {
        pairs[k] = parcom(pairs[k]);
        k++;
    }


    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            if(pairs[j] < pairs[i]) {
                int parcomp = pairs[j];
                pairs[j]= pairs[i];
                pairs[i] = parcomp;
            }
        }
    }

    if(k > 5) {
        for(int i = 0; i < 5; i++) {
            printf("%d ", pairs[i]);
        }

    } else {
        for(int i = 0; i < k; i++) {
            printf("%d ", pairs[i]);
        }
    }

}