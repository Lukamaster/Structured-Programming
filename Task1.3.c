#include <stdio.h>

int count = 0;

int evenOdd(int array[], int n, int i) {
    if(i >= n) {
        if(count <= 0) {
        	printf("No such elements!");
        }
        return 0;
    }
    int temp = array[i];

    if((temp % 10) % 2 == 0) {
        while(temp > 9) {
            temp /= 10;
        }
        if(temp % 2 != 0) {
            count++;
            printf("%d\n", array[i]);
        }
        return evenOdd(array, n, i+1);
    } else {
        return evenOdd(array, n, i+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    evenOdd(array, n, 0);
    return 0;
}