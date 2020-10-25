#include <stdio.h>
#define max 100

int factorial(int n) {
    if(n >= 1) {
        return n * factorial(n-1);
    } else
        return 1;
}

int strongNumber(int n) {

    int t, sum = 0, digit;
    t = n;

    while(t > 0) {
        digit = t % 10;
        sum += factorial(digit);
        t /= 10;
    }

    if(sum == n) {
        return 1;
    } else
        return 0;
}

int main() {

    int a;
    scanf("%d", &a);
    int array[max] = {};

    for(int i = 0; i < a; i++) {
        scanf("%d", &array[i]);
    }

    printf("Silni broevi:\n");

    for(int j = 0; j < a; j++) {
        if(strongNumber(array[j]) == 1) {
            printf("%d\n", array[j]);
        }
    }
    return 0;
}