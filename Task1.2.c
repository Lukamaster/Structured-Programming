#include <stdio.h>

int arrAbbreviate(int array[], int n, int k) {
    int temp, digit, abbNum = 0, currentFactor=1, largest = 0;

    for(int i = 0; i < n; i++) {
        temp = array[i];
        while(temp > 0) {
            digit = temp % 10;
            temp /= 10;

            if(digit > k) {
                abbNum += digit*currentFactor;
                currentFactor *= 10;
            }
        }
        if(largest < abbNum) {
            largest = abbNum;
        }
        currentFactor = 1;
        abbNum = 0;
    }
    return largest;
}

int main() {
    int n, k, max;
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);


    printf("%d", arrAbbreviate(array, n, k));
    return 0;
}