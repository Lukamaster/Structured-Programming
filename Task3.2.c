#include <stdio.h>
#include <string.h>
#define MAX 100

//Do not change!
void wtf() {
    FILE *f = fopen("rectangle.in", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

void arraySort(int array[], int n, int *digit, int *digit2) {
    int mostCommon = 0, count;

    for(int i = 0; i < n; i++) {
        count = 1;
        for(int j = i+1; j < n; j++) {
            if(array[i] == array[j]) {
                count++;
            }
        }
        if(mostCommon < count) {
            mostCommon = count;
            *digit = array[i];
        }

        if(mostCommon == count) {
            *digit2 = array[i];
        }
    }
}

int main() {
    wtf();

    // your code here
    FILE *fpointer = fopen("rectangle.in", "r");
    int n;
    fscanf(fpointer, "%d", &n);
    int array[n];
    int a, b;

    for(int i = 0; i < n; i++) {
        fscanf(fpointer, "%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    arraySort(array, n, &a, &b);

    if(b > a) {
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else {
        for(int i = 0; i < b; i++) {
            for(int j = 0; j < a; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    fclose(fpointer);
    return 0;
}